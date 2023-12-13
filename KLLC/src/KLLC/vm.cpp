#include "KLLC/KLLC.h"
#include <cstring>
namespace kllc{
    byte* VM::EXECUTE(byte* value,size_t size,size_t* return_size,Namespace* actual){
        uint64_t pos=0;
        uint64_t AC;
        byte* RETREG;
        size_t RETREG_SIZE;
        NamespaceSelector selector={&rootNamespace};
        selector.actualMainNamespace=actual;
        byte* v;
        reg r;
        size_t vs;
        scope s;
        size_t vrs;
        byte* vr;
        uint64_t _64=0;
        while(pos<size){
            byte c=*(value+pos);
            pos++;
            if(c==0){
                break;
            }
            switch (c)
            {
            case LOAD_GLOBAL:
                r=*(value+pos);
                pos+=sizeof(reg);
                v=rootNamespace.getVariable(*(value+pos),&vs);
                pos+=sizeof(global);
                if(r==0){
                    AC=*(v);
                }
                break;
            case LOAD_LOCAL:
                r=*(value+pos);
                pos+=sizeof(reg);
                v=selector.currentNamespace->getVariable(*(value+pos),&vs);
                pos+=sizeof(local);
                if(r==0){
                    AC=*(v);
                }
                break;
            case EXIT_SCOPE:
                selector.moveToParent();
                break;
            case RESET_SCOPE:
                selector.resetToActual();
                break;
            case ENTER_SCOPE:
                s=*(value+pos);
                pos+=sizeof(scope);
                selector.enterChild(s);
                break;
            case EXECUTE_LOCAL:
                v=selector.currentNamespace->getVariable(*(value+pos),&vs);
                s=selector.currentNamespace->children_.size();
                selector.currentNamespace->createChildNamespace(s);
                selector.enterChild(*(value+pos));
                pos+=sizeof(local);
                vr=this->EXECUTE(v,vs,&vrs,selector.currentNamespace);
                selector.moveToParent();
                selector.currentNamespace->removeChildNamespace(s);
                RETREG=vr;
                RETREG_SIZE=vrs;
                break;
            case EXECUTE_GLOBAL:
                v=rootNamespace.getVariable(*(value+pos),&vs);
                s=rootNamespace.children_.size();
                rootNamespace.createChildNamespace(s);
                selector.resetToRoot();
                selector.enterChild(*(value+pos));
                pos+=sizeof(local);
                vr=this->EXECUTE(v,vs,&vrs,selector.currentNamespace);
                selector.moveToParent();
                rootNamespace.removeChildNamespace(s);
                RETREG=vr;
                RETREG_SIZE=vrs;
                break;
            case SUM4:
                r=*(value+pos);
                pos+=sizeof(reg);
                std::memcpy(&_64, value+pos, sizeof(uint64_t));
                if(r==0){
                    AC+=_64;
                }
                pos+=sizeof(_64);
                break;
            case RETURN1:
                v=rootNamespace.getVariable(*(value+pos),return_size);
                return v;
                break;
            case RETURN2:
                v=selector.currentNamespace->getVariable(*(value+pos),return_size);
                return v;
                break;
            case RETURN3:
                r=*(value+pos);
                if(r==0){
                    RETREG=new byte[sizeof(uint64_t)];
                    std::memcpy(RETREG, &AC, sizeof(uint64_t));
                    *return_size=sizeof(uint64_t);
                    return RETREG;
                }
                break;
            case MOVE_64_TO_REG:
                r=*(value+pos);
                pos+=sizeof(reg);
                if(r==0){
                    std::memcpy(&AC, value+pos, sizeof(uint64_t));
                }
                pos+=sizeof(AC);
                break;
            default:
                pos=size;
                break;
            }
        }
        *return_size=0;
        return new byte[0];
    }
    byte* VM::EVAL_FILE(std::string path,size_t* return_size){
        size_t fs;
        byte* fc=readFile(path,fs);
        if(temPrefixo(fc,fs,".KLLC   ")){
            scope names=rootNamespace.children_.size();
            rootNamespace.createChildNamespace(names);
            byte* rets=EXECUTE(fc+8,fs-8,return_size,&rootNamespace.children_[names]);
            rootNamespace.removeChildNamespace(names);
            return rets;
        }
        *return_size=0;
        return new byte[0];
    }
}