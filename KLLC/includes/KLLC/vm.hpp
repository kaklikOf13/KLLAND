#ifndef kllc_vm_h
#define kllc_vm_h
#include "namespace.hpp"
namespace kllc{
    class Debuger;
    class VM{
        public:
            Namespace rootNamespace;
            
            VM(){
                
            }
            byte* EXECUTE(byte* value,size_t size,size_t* return_size,Namespace* actual);
            byte* EVAL_FILE(std::string path,size_t* return_size);
        protected:
            
    };
}
#endif