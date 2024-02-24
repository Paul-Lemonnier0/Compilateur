#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "contexte.hh"
#include "figure.hh"
#include "noeud.hh"
#include <memory>
#include <fstream>

class Driver {
private:
    Contexte variables;   
    std::shared_ptr<Caneva> _caneva;
    ArbreSyntaxique _arbreSyntaxique;

public:
    Driver();
    ~Driver();

    const   Contexte& getContexte() const;
    double  getVariable(const std::string& name) const;
    void    setVariable(const std::string& name, double value);

    std::shared_ptr<Caneva> getCaneva() const;
    void setCaneva(std::shared_ptr<Caneva> caneva);




    

    void addNode(Noeud * node) {
        _arbreSyntaxique.addNode(node);
    }

    FigureNode * accesFigureIndex(int index, FigureTypes figureType) const {
        return _arbreSyntaxique.accesFigureIndex(index, figureType);
    }

    FigureNode * accesVariableValue(std::string const & varName) const{
        return _arbreSyntaxique.accesVariableValue(varName);
    }

    void setAttributVariableFigure(FigureNode * figure, std::string const & attribut, std::string value){
        _arbreSyntaxique.setAttributVariableFigure(figure, attribut, value);
    }

    void analyseCode(ArbreSyntaxique arbre) {
        std::cout<<arbre.getArbre().size();

        std::string svg = arbre.analyseCode();

        std::ofstream svgFile("resultSVG.svg");
        svgFile << svg;
        svgFile.close();
    }

};

#endif
