#include "contexte.hh"

double& Contexte::get(const std::string & nom) {
    return variables_double[nom];
}

const double& Contexte::get(const std::string & nom) const {
    return variables_double.at(nom);
}

double& Contexte::operator[](const std::string & nom) {
    return variables_double[nom];
}

const double& Contexte::operator[](const std::string & nom) const {
    return variables_double.at(nom);
}