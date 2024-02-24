#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "contexte.hh"
#include "figure.hh"
#include "arbre.hh"
#include <memory>
#include <fstream>

class Driver {
private:
    Contexte variables;   
    ArbreSyntaxique _arbreSyntaxique;

public:
    Driver();
    ~Driver();

    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);


    void addNode(std::shared_ptr<Noeud> node) {
        _arbreSyntaxique.addNode(node);
    }

    std::shared_ptr<FigureNode> accesFigureIndex(int index, FigureTypes figureType) const {
        return _arbreSyntaxique.accesFigureIndex(index, figureType);
    }

    std::shared_ptr<FigureNode> accesVariableValue(std::string const & varName) const{
        return _arbreSyntaxique.accesVariableValue(varName);
    }

    void analyseCode(ArbreSyntaxique arbre) {
        std::cout<<arbre.getArbre().size();

        std::string svg = arbre.analyseCode(variables);

        std::ofstream svgFile("resultSVG.svg");
        svgFile << svg;
        svgFile.close();
    }
/*
    FonctionNode * accesFonction(std::vector<Noeud *> nodes, std::string const & fonctionName) const {
        for(auto node: nodes){
            if (FonctionNode* fonction = dynamic_cast<FonctionNode*>(node)){
                if(fonction->nom() == fonctionName){
                    return fonction;
                }
            }
        }

        return nullptr;
    }

    void compile() {

    }

    std::string analyseFonction(std::vector<Noeud *> nodes, Contexte & contexte) {
        std::string svg = "";

        for(auto node: nodes) {
            if(AppelFonctionNode * appelFonctionNode = dynamic_cast<AppelFonctionNode *>(*node)){
                if(FonctionNode * fonction = accesFonction(nodes, appelFonctionNode->nom())){
                    bool isArgsOk = fonction->setArgs(appelFonctionNode->args(contexte));
                    if(isArgsOk){
                        svg += analyseFonction(fonction->instructions(), fonction->getContexte());
                    }
                }
            }
        }

        return svg;
    }
*/
};

#endif
