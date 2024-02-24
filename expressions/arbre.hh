#pragma once

#include "noeud.hh"
#include "figure.hh"
#include "boucles.hh"
#include "condition.hh"
#include "fonction.hh"

class ArbreSyntaxique {
    protected:
        std::vector<std::shared_ptr<Noeud>> _arbre;

    public:
        ArbreSyntaxique() = default;

        void addNode(std::shared_ptr<Noeud > node){
            if (std::shared_ptr<CanevaNode> c = std::dynamic_pointer_cast<CanevaNode>(node)){
                std::shared_ptr<CanevaNode> caneva = getCanevaNode();
                if(caneva != nullptr){
                    caneva->setWidth(c->width());
                    caneva->setHeight(c->height());
                }

                else {
                    _arbre.push_back(node);
                }
            }

            else {
                _arbre.push_back(node);
            }
        }

        std::vector<std::shared_ptr<Noeud>> getArbre() const {
            return _arbre;
        }

        std::shared_ptr<CanevaNode> getCanevaNode(bool deleteCaneva = false) const {
            for(auto noeud: _arbre){
                if (std::shared_ptr<CanevaNode> caneva = std::dynamic_pointer_cast<CanevaNode>(noeud)){
                    return caneva;
                }
            }

            return nullptr;
        }

        std::shared_ptr<FigureNode> accesFigureIndex(int index, FigureTypes figureType) const;
        std::shared_ptr<FigureNode> accesVariableValue(std::string const & varName) const;
        std::shared_ptr<FonctionNode> accesFonction(std::string const & fonctionName) const;
        std::shared_ptr<FigureNode> getFigureNode(std::shared_ptr<AccesFigureNode> accesFigure) const;

        std::string analyseCode(Contexte & contexte);
        std::string analyseNodes(std::vector<std::shared_ptr<Noeud>> nodes, Contexte & contexte);
        void setupAllVariable(std::vector<std::shared_ptr<Noeud>> nodes, Contexte & contexte);
};