#include "noeud.hh"

class FonctionNode: public NoeudInterne {
    private:
        std::string _nom;
        Contexte _variables;
        std::vector<std::string> _argsNames;
    
    public:
        FonctionNode(std::vector<std::shared_ptr<Noeud>> instructions, std::string nom, std::vector<std::string> argsNames):
            NoeudInterne(instructions), _nom(nom), _argsNames(argsNames) {}

        std::string nom() const {
            return _nom;
        }

        bool setArgs(std::vector<double> argsValues) {
            if(argsValues.size() == _argsNames.size()){
                for(std::size_t i(0); i < _argsNames.size(); ++i){
                    _variables[_argsNames[i]] = argsValues[i];
                }

                return true;
            }

            return false;
        }

        Contexte & getContexte() {
            return _variables;
        }
};


class AppelFonctionNode: public Noeud {
    private:
        std::string _nom;
        std::vector<ExpressionPtr> _args;

    public:
        AppelFonctionNode(std::string nom, std::vector<ExpressionPtr> args):
            Noeud(), _nom(nom), _args(args) {}


        std::vector<double> args(Contexte & contexte) const {
            std::vector<double> calculatedArgs;

            for(auto arg: _args){
                calculatedArgs.push_back(arg->calculer(contexte));
            }
            return calculatedArgs;
        }  

        std::string nom() const {
            return _nom;
        }
};