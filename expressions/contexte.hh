#ifndef context_h
#define context_h

#include <string>
#include <map>
#include <vector>
#include <iostream>

class Contexte {
private:
    std::map<std::string, double> variables_double;
    std::map<std::string, bool> variables_bool;
    std::map<std::string, std::string> variables_string;
    
public:
    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    double& get(const std::string & nom);
    const double& get(const std::string & nom) const;
    
    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

    bool hasDoubleKey(const std::string & nom) const {
        if(variables_double.find(nom) == variables_double.end()){
            return false;
        }
        return true;
    }

    void setDoubleVar(std::string nom, double val) {
        variables_double[nom] = val;
    }

    void setBoolVar(std::string nom, bool val) {
        variables_bool[nom] = val;
    }

    void setStringVar(std::string nom, std::string val) {
        variables_string[nom] = val;
    }

    bool getBoolVar(std::string nom) {
        if(variables_bool.find(nom) == variables_bool.end()){
            return false;
        }
        return variables_bool[nom];
    }

    std::string getStringVar(std::string nom) {
        if(variables_string.find(nom) == variables_string.end()){
            return "none";
        }

        return variables_string[nom];
    }
};


#endif