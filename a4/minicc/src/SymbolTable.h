//
// Created by Fan Long on 2020/12/5.
//

#ifndef MINICC_SYMBOLTABLE_H
#define MINICC_SYMBOLTABLE_H

//add more header files if your want
//You may need assert function
#include <cassert>
#include "Types.h"
#include <map>

namespace llvm {
    class Value;
}

namespace minicc {


    struct VarSymbolEntry {
        Type VarType;
        llvm::Value *LLVMValue;

        explicit VarSymbolEntry(Type varType) : VarType(varType), LLVMValue(nullptr) { }
    };

    class VarSymbolTable {

        std::map<std::string, VarSymbolEntry> Table;

    public:
        //define your member variables and functions
        void insert_varsym(const std::string &name, Type type) {
            Table.insert(std::make_pair(name, VarSymbolEntry(type)));
        }

        bool contains_var(const std::string &name) {
            return Table.find(name) != Table.end();
        }

        VarSymbolEntry *get_varsym(const std::string &name) {
            assert(contains_var(name));
            return &Table.find(name)->second;
        }


    };

    struct FuncSymbolEntry {
        Type ReturnType;
        std::vector<Type> ParameterTypes;
        bool HasBody;

        FuncSymbolEntry(Type retType, const std::vector<Type> &paraTypes, bool hasBody) : ReturnType(retType), ParameterTypes(paraTypes), HasBody(hasBody) { }
    };

    class FuncSymbolTable {
        std::map<std::string, FuncSymbolEntry> Table;
    public:
        //define your member variables and functions
        void insert_funcsym(const std::string &name, Type retType, const std::vector<Type> &paraTypes, bool hasBody) {
            Table.insert(std::make_pair(name, FuncSymbolEntry(retType, paraTypes, hasBody)));
        }

        bool contains_func(const std::string &name) {
            return Table.find(name) != Table.end();
        }

        FuncSymbolEntry *get_funcsym(const std::string &name) {
            assert(contains_func(name));
            return &Table.find(name)->second;
        }
    };
}

#endif //MINICC_SYMBOLTABLE_H
