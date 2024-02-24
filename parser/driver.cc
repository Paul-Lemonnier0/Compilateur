#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}


const Contexte& Driver::getContexte() const {
    //TODO Retourne le contexte pour qu'il soit accessible en dehors de la classe Driver
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    //TODO Retourne la valeur de la variable name
    return 0;
}

void Driver::setVariable(const std::string & name, double value) {
    //TODO Affecte une valeur à une variable avec l'utilisation du contexte variables
}

std::shared_ptr<Caneva> Driver::getCaneva() const{
    return _caneva;
}
void Driver::setCaneva(std::shared_ptr<Caneva> caneva){
    _caneva = caneva;
}

