#ifndef kllc_namespace_h
#define kllc_namespace_h
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "types.hpp"
namespace kllc{
    class Namespace {
    public:
        Namespace() {}
        std::map<size_t, Namespace> children_;
        void addVariable(local name, byte* value,size_t var_size);
        byte* getVariable(local name,size_t* ret_size);
        void removeVariable(local name);
        void removeChildNamespace(scope name);
        void createChildNamespace(scope name);
        Namespace* parent_ = nullptr;
    private:
        std::map<local, byte*> variables_;
        std::map<scope, size_t> variables_size_;
    };

    class NamespaceSelector {
    public:
        NamespaceSelector(Namespace* rootNamespace);
        NamespaceSelector(){}
        bool moveToParent();
        bool enterChild(size_t name);
        void resetToRoot();
        void resetToActual();
        void set_actual_main_namespace();
        Namespace* rootNamespace;
        Namespace* currentNamespace;
        Namespace* actualMainNamespace=nullptr;
    };
}
#endif