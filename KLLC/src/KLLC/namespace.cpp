#include "KLLC/KLLC.h"
namespace kllc{
    void Namespace::addVariable(local name, byte* value,size_t var_size) {
        variables_[name] = value;
        variables_size_[name]=var_size;
    }
    byte* Namespace::getVariable(local name,size_t* ret_size) {
        if (variables_.count(name)) {
            *ret_size=variables_size_[name];
            return variables_[name];
        }
        std::cerr << "Variável '" << name << "' não encontrada." << std::endl;
        return 0;
    }
    void Namespace::removeVariable(local name){
        delete[]this->variables_[name];
        this->variables_.erase(name);
        this->variables_size_.erase(name);
    }
    void Namespace::removeChildNamespace(scope name){
        children_.erase(name);
    }
    void Namespace::createChildNamespace(scope name) {
        children_[name] = Namespace();
    }
    NamespaceSelector::NamespaceSelector(Namespace* rootNamespace) {
        this->rootNamespace=rootNamespace;
        this->currentNamespace=rootNamespace;
    }
    bool NamespaceSelector::moveToParent(){
        if (currentNamespace->parent_) {
            currentNamespace = currentNamespace->parent_;
            return true;
        }
        return false;
    }
    bool NamespaceSelector::enterChild(size_t name) {
        auto it = currentNamespace->children_.find(name);
        if (it != currentNamespace->children_.end()) {
            Namespace* oldnamespace=currentNamespace;
            currentNamespace = &(it->second);
            currentNamespace->parent_=oldnamespace;
            return true;
        }
        return false;
    }
    void NamespaceSelector::resetToRoot() {
        currentNamespace = rootNamespace;
    }
    void NamespaceSelector::resetToActual(){
        this->currentNamespace=actualMainNamespace;
    }
    void NamespaceSelector::set_actual_main_namespace(){
        actualMainNamespace=currentNamespace;
    }
}