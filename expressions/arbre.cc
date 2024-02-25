#include "arbre.hh"

std::shared_ptr<FigureNode> ArbreSyntaxique::accesFigureIndex(std::vector<std::shared_ptr<Noeud>> nodes, int index, FigureTypes figureType) const {
    int i = 0;

    // if(nodes != _arbre) {
    //     nodes.insert( nodes.end(), _arbre.begin(), _arbre.end());
    // }

    for(auto noeud: nodes){
        switch (figureType)
        {
            case FigureTypes::carre:
            
                if (std::shared_ptr<CarreNode> carre = std::dynamic_pointer_cast<CarreNode>(noeud)){
                    if(i == index){
                        return carre;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<CarreNode> carre = std::dynamic_pointer_cast<CarreNode>(declaVar->value())){
                        if(i == index){
                            return carre;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::rectangle:
            
                if (std::shared_ptr<RectangleNode> rectangle = std::dynamic_pointer_cast<RectangleNode>(noeud)){
                    if(i == index){
                        return rectangle;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<RectangleNode> rectangle = std::dynamic_pointer_cast<RectangleNode>(declaVar->value())){
                        if(i == index){
                            return rectangle;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::triangle:
            
                if (std::shared_ptr<TriangleNode> triangle = std::dynamic_pointer_cast<TriangleNode>(noeud)){
                    if(i == index){
                        return triangle;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<TriangleNode> triangle = std::dynamic_pointer_cast<TriangleNode>(declaVar->value())){
                        if(i == index){
                            return triangle;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::cercle:
            
                if (std::shared_ptr<CercleNode> cercle = std::dynamic_pointer_cast<CercleNode>(noeud)){
                    if(i == index){
                        return cercle;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<CercleNode> cercle = std::dynamic_pointer_cast<CercleNode>(declaVar->value())){
                        if(i == index){
                            return cercle;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::ellipse:
            
                if (std::shared_ptr<EllipseNode> ellipse = std::dynamic_pointer_cast<EllipseNode>(noeud)){
                    if(i == index){
                        return ellipse;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<EllipseNode> ellipse = std::dynamic_pointer_cast<EllipseNode>(declaVar->value())){
                        if(i == index){
                            return ellipse;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::ligne:
            
                if (std::shared_ptr<LigneNode> ligne = std::dynamic_pointer_cast<LigneNode>(noeud)){
                    if(i == index){
                        return ligne;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<LigneNode> ligne = std::dynamic_pointer_cast<LigneNode>(declaVar->value())){
                        if(i == index){
                            return ligne;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::chemin:
            
                if (std::shared_ptr<CheminNode> chemin = std::dynamic_pointer_cast<CheminNode>(noeud)){
                    if(i == index){
                        return chemin;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<CheminNode> chemin = std::dynamic_pointer_cast<CheminNode>(declaVar->value())){
                        if(i == index){
                            return chemin;
                        }

                        else index -= 1;
                    }
                }
                
                break;
            case FigureTypes::texte:
            
                if (std::shared_ptr<TexteNode> texte = std::dynamic_pointer_cast<TexteNode>(noeud)){
                    if(i == index){
                        return texte;
                    }

                    else index -= 1;
                }
                

                else if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
                    if (std::shared_ptr<TexteNode> texte = std::dynamic_pointer_cast<TexteNode>(declaVar->value())){
                        if(i == index){
                            return texte;
                        }

                        else index -= 1;
                    }
                }
                
                break;
        }
    }

    return nullptr;
}

std::shared_ptr<FigureNode> ArbreSyntaxique::accesVariableValue(std::vector<std::shared_ptr<Noeud>> nodes, std::string const & varName) const {

    for(auto noeud: nodes){
        if (std::shared_ptr<DeclarationVariable> declaVar = std::dynamic_pointer_cast<DeclarationVariable>(noeud)){
            if(declaVar->nomVariable() == varName){
                return declaVar->value();
            }
        }
    }

    return nullptr;
}

std::shared_ptr<FonctionNode> ArbreSyntaxique::accesFonction(std::vector<std::shared_ptr<Noeud>> nodes, std::string const & fonctionName) const {
    
    // std::shared_ptr<FonctionNode> fonctionDessiner = accesFonction(_arbre, "dessiner");
    // std::vector<std::shared_ptr<Noeud>> rootNodes;
    // rootNodes = fonctionDessiner->instructions();
    // rootNodes = _arbre;

    if(nodes != _arbre) {
        nodes.insert( nodes.end(), _arbre.begin(), _arbre.end());
    }

    for(auto noeud: nodes){
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

    //AVEC POINT D'ENTREE DESSINER

    if(std::shared_ptr<FonctionNode> fonction = accesFonction(_arbre, "dessiner")){
        std::shared_ptr<CanevaNode> caneva = getCanevaNode(fonction->instructions());

        if(caneva != nullptr){
            svg += "<svg version=\"1.1\"" + caneva->analyseCode(contexte) + " xmlns=\"http://www.w3.org/2000/svg\">\n";

            svg += analyseNodes(fonction->instructions(), fonction->instructions(), fonction->getContexte());
            
            svg += "</svg>";
        }
    }

    //SANS POINT D'ENTREE DESSINER

    
    // std::shared_ptr<CanevaNode> caneva = getCanevaNode(_arbre);

    // if(caneva != nullptr){
    //     svg += "<svg version=\"1.1\"" + caneva->analyseCode(contexte) + " xmlns=\"http://www.w3.org/2000/svg\">\n";

    //     svg += analyseNodes(_arbre, _arbre, contexte);

    //     svg += "</svg>";
    // }
    

    return svg;
}

std::shared_ptr<FigureNode> ArbreSyntaxique::getFigureNode(std::vector<std::shared_ptr<Noeud>> nodes, std::shared_ptr<AccesFigureNode> accesFigure) const{
    if(std::shared_ptr<AccesIndexNode> accesIndex = std::dynamic_pointer_cast<AccesIndexNode>(accesFigure)){     
        return accesFigureIndex(nodes, accesIndex->index(), accesIndex->type());
    }

    else {
        std::shared_ptr<AccesVariableNode> accesVariable = std::dynamic_pointer_cast<AccesVariableNode>(accesFigure);
        
        return accesVariableValue(nodes, accesVariable->varName());
    }
}


std::string ArbreSyntaxique::analyseNodes(std::vector<std::shared_ptr<Noeud>> rootNodes, std::vector<std::shared_ptr<Noeud>> nodes, Contexte & contexte) {
    std::string svg = "";

    for(auto node = nodes.rbegin(); node != nodes.rend(); ++node){
        if(std::shared_ptr<DeclarationVariableSimple> var = std::dynamic_pointer_cast<DeclarationVariableSimple>(*node)){
            var->createVariable(contexte);
        }

        else if(std::shared_ptr<IfNode> ifNode = std::dynamic_pointer_cast<IfNode>(*node)){
            std::vector<std::shared_ptr<ConditionNode>> conditions = ifNode->conditions();
            for(auto condition: conditions){
                if(std::shared_ptr<FigureConditionNode> figureCondNode = std::dynamic_pointer_cast<FigureConditionNode>(condition)){   
                    std::vector<std::shared_ptr<Noeud>> nodes_temp = nodes;  

                    if(nodes_temp != rootNodes) {
                        nodes_temp.insert( nodes_temp.end(), rootNodes.begin(), rootNodes.end());
                    }             

                    figureCondNode->setFigure(getFigureNode(nodes_temp, figureCondNode->getAccesFigureNode()));
                }
            }

            if(ifNode->evaluate(contexte)){
                svg += analyseNodes(rootNodes, ifNode->instructions(), contexte);
            }

            else {
                svg += analyseNodes(rootNodes, ifNode->elseInstructions(), contexte);
            }
        }

        else if(std::shared_ptr<AppelFonctionNode> appelFonctionNode = std::dynamic_pointer_cast<AppelFonctionNode>(*node)){
            if(std::shared_ptr<FonctionNode> fonction = accesFonction(rootNodes, appelFonctionNode->nom())){
                bool isArgsOk = fonction->setArgs(appelFonctionNode->args(contexte));
                if(isArgsOk){
                    std::vector<std::shared_ptr<Noeud>> nodes_temp = nodes;  

                    if(nodes_temp != rootNodes) {
                        nodes_temp.insert( nodes_temp.end(), rootNodes.begin(), rootNodes.end());
                    }  

                    svg += analyseNodes(nodes_temp, fonction->instructions(), fonction->getContexte());
                }
            }
        }

        else if(std::shared_ptr<ForLoopNode> forLoopNode = std::dynamic_pointer_cast<ForLoopNode>(*node)){
            std::vector<std::shared_ptr<Noeud>> nodes_temp = nodes;  

            if(nodes_temp != rootNodes) {
                nodes_temp.insert( nodes_temp.end(), rootNodes.begin(), rootNodes.end());
            }  
            for(int i = 0; i < forLoopNode->compteur()->calculer(contexte); ++i){

                svg += analyseNodes(nodes_temp, forLoopNode->instructions(), contexte);
            }
        }
        
        else if(std::shared_ptr<WhileNode> whileNode = std::dynamic_pointer_cast<WhileNode>(*node)){
            std::vector<std::shared_ptr<Noeud>> nodes_temp = nodes;  

            if(nodes_temp != rootNodes) {
                nodes_temp.insert( nodes_temp.end(), rootNodes.begin(), rootNodes.end());
            }  
            while(whileNode->evaluate(contexte)){
                svg += analyseNodes(nodes_temp, whileNode->instructions(), contexte);
            }
        }

        else if(std::shared_ptr<ModificationFigureNode> modNode = std::dynamic_pointer_cast<ModificationFigureNode>(*node)){
            std::vector<std::shared_ptr<Noeud>> nodes_temp = nodes;  

            if(nodes_temp != rootNodes) {
                nodes_temp.insert( nodes_temp.end(), rootNodes.begin(), rootNodes.end());
            }

            modNode->setFigure(getFigureNode(nodes_temp, modNode->getAccesFigureNode()));
            modNode->modificate(contexte);
        }
    }

    for(auto node = nodes.rbegin(); node != nodes.rend(); ++node){
        if(std::shared_ptr<NoeudInterpretable> interpretableNode = std::dynamic_pointer_cast<NoeudInterpretable>(*node)){
            if (!std::dynamic_pointer_cast<CanevaNode>(*node)){   
                std::string str = interpretableNode->analyseCode(contexte);
                svg += str;    
            }
        }

        else if(std::shared_ptr<AffectationSimpleVariableNode> affectationNode = std::dynamic_pointer_cast<AffectationSimpleVariableNode>(*node)){
            affectationNode->setVariable(contexte);
        }
    }

    return svg;
}