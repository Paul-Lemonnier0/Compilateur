#include "arbre.hh"

std::shared_ptr<FigureNode> ArbreSyntaxique::accesFigureIndex(int index, FigureTypes figureType) const {
    int i = 0;

    for(auto node = _arbre.rbegin(); node != _arbre.rend(); ++node){
        switch (figureType)
        {
            case FigureTypes::carre:
            
                if (std::shared_ptr<CarreNode> carre = std::dynamic_pointer_cast<CarreNode>((*node))){
                    if(i == index){
                        return carre;
                    }

                    else ++i;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>((*node))){
                    if (std::shared_ptr<CarreNode> carre = std::dynamic_pointer_cast<CarreNode>(declaVar->value())){
                        if(i == index){
                            return carre;
                        }

                        else ++i;
                    }
                }
                
                break;

            case FigureTypes::triangle:
            
                if (std::shared_ptr<TriangleNode> triangle = std::dynamic_pointer_cast<TriangleNode>((*node))){
                    if(i == index){
                        return triangle;
                    }

                    else ++i;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>((*node))){
                    if (std::shared_ptr<TriangleNode> triangle = std::dynamic_pointer_cast<TriangleNode>(declaVar->value())){
                        if(i == index){
                            return triangle;
                        }

                        else ++i;
                    }
                }
                
                break;
        }
    }

    return nullptr;
}

std::shared_ptr<FigureNode> ArbreSyntaxique::accesVariableValue(std::string const & varName) const {
    
    for(auto noeud: _arbre){
        if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
            if(declaVar->nomVariable() == varName){
                return declaVar->value();
            }
        }
    }

    return nullptr;
}

std::shared_ptr<FonctionNode> ArbreSyntaxique::accesFonction(std::string const & fonctionName) const {
    
    for(auto noeud: _arbre){
        if (std::shared_ptr<FonctionNode> fonction = std::dynamic_pointer_cast<FonctionNode>(noeud)){
            if(fonction->nom() == fonctionName){
                return fonction;
            }
        }
    }

    return nullptr;
}

std::string ArbreSyntaxique::analyseCode(Contexte & contexte) {

    std::string svg = "";

    std::shared_ptr<CanevaNode> caneva = getCanevaNode();

    if(caneva != nullptr){
        svg += "<svg version=\"1.1\"" + caneva->analyseCode(contexte) + " xmlns=\"http://www.w3.org/2000/svg\">\n";

        svg += analyseNodes(_arbre, contexte);

        svg += "</svg>";
    }

    return svg;
}

void ArbreSyntaxique::setupAllVariable(std::vector<std::shared_ptr<Noeud>> nodes, Contexte & contexte) {    

}

std::shared_ptr<FigureNode> ArbreSyntaxique::getFigureNode(std::shared_ptr<AccesFigureNode> accesFigure) const{
    if(std::shared_ptr<AccesIndexNode> accesIndex = std::dynamic_pointer_cast<AccesIndexNode>(accesFigure)){     
        return accesFigureIndex(accesIndex->index(), accesIndex->type());
    }

    else {
        std::shared_ptr<AccesVariableNode> accesVariable = std::dynamic_pointer_cast<AccesVariableNode>(accesFigure);
        
        return accesVariableValue(accesVariable->varName());
    }
}


std::string ArbreSyntaxique::analyseNodes(std::vector<std::shared_ptr<Noeud>> nodes, Contexte & contexte) {
    std::string svg = "";
    
    for(auto node = nodes.rbegin(); node != nodes.rend(); ++node){
        if(std::shared_ptr<DeclarationVariableSimple> var = std::dynamic_pointer_cast<DeclarationVariableSimple>(*node)){
            var->createVariable(contexte);
        }
        
        else if(std::shared_ptr<AffectationSimpleVariableNode> affectationNode = std::dynamic_pointer_cast<AffectationSimpleVariableNode>(*node)){
            affectationNode->setVariable(contexte);
        }

        else if(std::shared_ptr<IfNode> ifNode = std::dynamic_pointer_cast<IfNode>(*node)){
            std::vector<std::shared_ptr<ConditionNode>> conditions = ifNode->conditions();
            for(auto condition: conditions){
                if(std::shared_ptr<FigureConditionNode> figureCondNode = std::dynamic_pointer_cast<FigureConditionNode>(condition)){                        
                    figureCondNode->setFigure(getFigureNode(figureCondNode->getAccesFigureNode()));
                }
            }

            if(ifNode->evaluate(contexte)){
                svg += analyseNodes(ifNode->instructions(), contexte);
            }

            else {
                svg += analyseNodes(ifNode->elseInstructions(), contexte);
            }
        }

        else if(std::shared_ptr<AppelFonctionNode> appelFonctionNode = std::dynamic_pointer_cast<AppelFonctionNode>(*node)){
            if(std::shared_ptr<FonctionNode> fonction = accesFonction(appelFonctionNode->nom())){
                bool isArgsOk = fonction->setArgs(appelFonctionNode->args(contexte));
                if(isArgsOk){
                    svg += analyseNodes(fonction->instructions(), fonction->getContexte());
                }
            }
        }

        else if(std::shared_ptr<ForLoopNode> forLoopNode = std::dynamic_pointer_cast<ForLoopNode>(*node)){
            for(int i = 0; i < forLoopNode->compteur()->calculer(contexte); ++i){
                svg += analyseNodes(forLoopNode->instructions(), contexte);
            }
        }
        
        else if(std::shared_ptr<WhileNode> whileNode = std::dynamic_pointer_cast<WhileNode>(*node)){
            while(whileNode->evaluate(contexte)){
                svg += analyseNodes(whileNode->instructions(), contexte);
            }
        }

        else if(std::shared_ptr<ModificationFigureNode> modNode = std::dynamic_pointer_cast<ModificationFigureNode>(*node)){
            modNode->setFigure(getFigureNode(modNode->getAccesFigureNode()));
            modNode->modificate(contexte);
        }
    }

    //Je dois le reverse à cause de mon recursif (j'ajoute mes éléments dans l'autre sens)

    for(auto node = nodes.rbegin(); node != nodes.rend(); ++node){
        if(*node != nullptr){
            if (!std::dynamic_pointer_cast<CanevaNode>(*node)){       
                std::string str = (*node)->analyseCode(contexte);
                svg += str;
            }
        }
    }

    return svg;
}