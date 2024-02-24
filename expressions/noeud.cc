#include "noeud.hh"

FigureNode * ArbreSyntaxique::accesFigureIndex(int index, FigureTypes figureType) const {
    int i = index;

    for(auto noeud: _arbre){
        switch (figureType)
        {
            case FigureTypes::carre:
            
                if (CarreNode* carre = dynamic_cast<CarreNode*>(noeud)){
                    if(i == 0){
                        return carre;
                    }

                    else --i;
                }
                

                else if (DeclarationVariable* declaVar = dynamic_cast<DeclarationVariable*>(noeud)){
                    if (CarreNode* carre = dynamic_cast<CarreNode*>(declaVar->value())){
                        if(i == 0){
                            return carre;
                        }

                        else --i;
                    }
                }
                
                break;
        }
    }

    return nullptr;
}

FigureNode * ArbreSyntaxique::accesVariableValue(std::string const & varName) const {
    
    for(auto noeud: _arbre){
        if (DeclarationVariable* declaVar = dynamic_cast<DeclarationVariable*>(noeud)){
            if(declaVar->nomVariable() == varName){
                return declaVar->value();
            }
        }
    }

    return nullptr;
}

void ArbreSyntaxique::setAttributVariableFigure(FigureNode * figure, std::string const & attribut, std::string const & value) const {
    figure->setAttribut(attribut, value);
}


/*

std::string ArbreSyntaxique::analyseCode() {
    std::string svg = "";

//    std::cout<<"Début interprétation des accès / modifications : \n";


    for(auto node = _arbre.begin(); node != _arbre.end(); ++node){
        ModificationNode * modNode = dynamic_cast<ModificationNode *>(*node);
//        std::cout<<"Analyse Node...\n";
        if(modNode != nullptr){
            AccesIndexNode * accesIndex = dynamic_cast<AccesIndexNode *>(modNode->getAccesFigureNode());
            
            if(accesIndex != nullptr){
                modNode->setFigure(accesFigureIndex(accesIndex->index(), accesIndex->type()));
            }

            else {
                AccesVariableNode * accesVariable = dynamic_cast<AccesVariableNode *>(*node);
                if(accesVariable != nullptr){
                    modNode->setFigure(accesVariableValue(accesVariable->varName()));
                }
            }

            modNode->analyseCode();
            delete *node;
            _arbre.erase(node);
        }
    }

 //   std::cout<<"Début interprétation des figures simples : \n";

    for(auto node: _arbre){
        CanevaNode* c = dynamic_cast<CanevaNode*>(node);
        if (c == nullptr){
            if(node != nullptr){
                std::string str = node->analyseCode();
                svg += str;
            }
        }
    }


    return svg;
}
*/

/*
std::string ArbreSyntaxique::analyseCode(std::vector<Noeud *> nodes) {
    std::string svg = "";

    for(auto node = nodes.begin(); node != nodes.end(); ++node){

        //Check des boucles

        IfNode * ifNode = dynamic_cast<IfNode *>(*node);
        if(ifNode != nullptr){
            if(ifNode->evaluate()){
                analyseNodes(ifNode->instructions());
            }
        }

        //Si pas une boucle alors

        else {
            //Caneva ?

            CanevaNode* c = dynamic_cast<CanevaNode*>(*node);
            if (c == nullptr){

                //Pas caneva -> on peut analyser transformer la node en svg car c'est une feuille

                if((*node) != nullptr){
                    std::string str = (*node)->analyseCode();
                    svg += str;
                }
            }
        }
    }

    return svg;
}

*/

std::string ArbreSyntaxique::analyseCode() {

    std::string svg = "";

    CanevaNode * caneva = getCanevaNode();

    if(caneva != nullptr){
        svg += "<svg version=\"1.1\"" + caneva->analyseCode() + " xmlns=\"http://www.w3.org/2000/svg\">\n";

        svg += analyseNodes(_arbre);

        svg += "</svg>";
    }

    return svg;
}


std::string ArbreSyntaxique::analyseNodes(std::vector<Noeud *> nodes) {
    std::string svg = "";

    for(auto node = nodes.begin(); node != nodes.end(); ++node){

        if(IfNode * ifNode = dynamic_cast<IfNode *>(*node)){
            ConditionNode * condition = ifNode->condition();
            if(condition != nullptr){
                if(CouleurConditionNode * couleurCondNode = dynamic_cast<CouleurConditionNode *>(condition)){
                    
                    AccesCouleurFigure * accesCouleurFigure = couleurCondNode->getAccesCouleurFigure();
                    if(accesCouleurFigure != nullptr){
                        
                        if(AccesIndexNode * accesIndex = dynamic_cast<AccesIndexNode *>(accesCouleurFigure->accesFigure())){
                            
                            FigureNode * fig = accesFigureIndex(accesIndex->index(), accesIndex->type());
                            if(fig != nullptr){

                                accesCouleurFigure->setColor(fig->getCouleur());
                            }
                        }

                        else {
                            std::cout<<"0\n";
                            AccesVariableNode * accesVariable = dynamic_cast<AccesVariableNode *>(accesCouleurFigure->accesFigure());
                            if(accesVariable != nullptr){
                                std::cout<<"1\n";
                                FigureNode * fig = accesVariableValue(accesVariable->varName());

                                if(fig != nullptr){
                                    std::cout<<"2 : "<<fig->getCouleur()<<"\n";
                                    accesCouleurFigure->setColor(fig->getCouleur());
                                }
                            }
                        }
                    }
                }
            }

            if(ifNode->evaluate()){
                svg += analyseNodes(ifNode->instructions());
            }
        }

        if(ModificationNode * modNode = dynamic_cast<ModificationNode *>(*node)){
            if(AccesIndexNode * accesIndex = dynamic_cast<AccesIndexNode *>(modNode->getAccesFigureNode())){
                modNode->setFigure(accesFigureIndex(accesIndex->index(), accesIndex->type()));
            }

            else {
                AccesVariableNode * accesVariable = dynamic_cast<AccesVariableNode *>(modNode->getAccesFigureNode());
                if(accesVariable != nullptr){
                    modNode->setFigure(accesVariableValue(accesVariable->varName()));
                }
            }

            modNode->analyseCode();
        }
    }

    for(auto node: nodes){
        CanevaNode* c = dynamic_cast<CanevaNode*>(node);
        if (c == nullptr){
            if(node != nullptr){
                std::string str = node->analyseCode();
                svg += str;
            }
        }
    }

    return svg;
}