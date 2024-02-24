#include "variable.hh"
#include <iostream> 

Variable::Variable(const std::string& nom) : _nom(nom) {}

double Variable::calculer(const Contexte & contexte) const {
    if(contexte.hasDoubleKey(_nom)){
        return contexte [_nom];
    }
    
    return 0;
}