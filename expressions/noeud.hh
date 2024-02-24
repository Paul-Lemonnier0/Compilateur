#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "figure.hh"

enum class operators { equal, not_equal, less_equal, greater_equal, less, greater };
enum class string_operators { equal, not_equal };

class Noeud {
    public:
        virtual ~Noeud() = default;

        virtual std::string analyseCode() = 0;
};

class PositionNode: public Noeud {
    private:
        Position _p;

    public:
        PositionNode(int x, int y):
            Noeud(), _p(x, y){}

        std::string tostring() const {
            return _p.tostring();
        }

        std::string analyseCode() override{
            return " x=\"" + std::to_string(_p.x()) + "\" y=\"" 
                + std::to_string(_p.y()) + "\"";
        }

        Position pos() const {
            return _p;
        }
};


class SizeNode: public Noeud {
    private:
        int _w, _h;

    public:
        SizeNode(int w, int h):
            Noeud(), _w(w), _h(h){}

        SizeNode(int size):
            Noeud(), _w(size), _h(size){}

        std::string tostring() const {
            return "[" + std::to_string(_w) + ";" + std::to_string(_h) + "]";
        }

        std::string analyseCode() override{
            return " width=\"" + std::to_string(_w) 
                + "\" height=\"" + std::to_string(_h) + "\"";
        }

        int width() const {
            return _w;
        }

        int height() const {
            return _h;
        }

        void setWidth(int width) {
            _w = width;
        }

        void setHeight(int height) {
            _h = height;
        }
};


class FigureNode: public Noeud {
    private:
        std::string _couleur, _remplissage;
        float _rotation, _opacite, _epaisseur;

    public:
        FigureNode():
            Noeud(),
            _couleur("none"),
            _remplissage("none"),
            _rotation(0),
            _opacite(1),
            _epaisseur(1)
        {}

        void setAttributs(std::map<std::string, std::string> attributs){
            for(const auto& elem : attributs)
            {
                setAttribut(elem.first, elem.second);           
            }
        }

        void setAttribut(std::string attribut, std::string value){
            if(attribut == "couleur" || attribut == "remplissage"){
                std::map<std::string, std::string> couleurs {
                    {"rouge", "red"},
                    {"vert", "green"},
                    {"bleu", "blue"},
                    {"jaune", "yellow"},
                    {"violet", "purple"},
                    {"magenta", "magenta"},
                    {"cyan", "cyan"},
                    {"noir", "black"},
                    {"blanc", "white"}
                };

                if(attribut == "couleur") {
                    if (couleurs.count(value)){
                        _couleur = couleurs[value];
                    }

                    else _couleur = value;
                }

                else {
                    if (couleurs.count(value)){
                        _remplissage = couleurs[value];
                    }

                    else _remplissage = value;
                }

            }

            else if(attribut == "rotation"){
                _rotation = std::stof(value);
            }

            else if(attribut == "opacite"){
                _opacite = std::stof(value) / 100;
            }

            else if(attribut == "epaisseur"){
                _epaisseur = std::stof(value);
            }
        }

        std::string getCouleur() const{
            std::map<std::string, std::string> couleurs {
                {"red", "rouge"},
                {"green", "vert"},
                {"blue", "bleu"},
                {"yellow", "jaune"},
                {"purple", "violet"},
                {"magenta", "magenta"},
                {"cyan", "cyan"},
                {"black", "noir"},
                {"white", "blanc"}
            };

            if (couleurs.count(_couleur)){
                return couleurs[_couleur];
            }
            
            return _couleur;
        }

        float getAttributNumberValue(std::string attribut) const {
            if(attribut == "rotation"){
                return _rotation;
            }

            else if(attribut == "opacite"){
                return _opacite;
            }

            else if(attribut == "epaisseur"){
                return _epaisseur;    
            }

            //faire un type enum ici
            return 0;
        }

        std::string analyseCode() override{

            return " stroke=\"" + _couleur +
                   "\" fill=\"" + _remplissage +
                   "\" opacity=\"" + std::to_string(_opacite) +
                   "\" stroke-width=\"" + std::to_string(_epaisseur) +
                   "\" transform=\"rotate(" + 
                   std::to_string(_rotation) + "," + std::to_string(center().x()) + "," + 
                   std::to_string(center().y()) + ")\"";
        }

        virtual Position center() const = 0;
};

class CarreNode: public FigureNode{
    private:
        PositionNode * _positionNode;
        SizeNode * _tailleNode;

    public:
        CarreNode(int x,  int y, int size):
            FigureNode(), 
            _positionNode(new PositionNode(x, y)),
            _tailleNode(new SizeNode(size))
        {}

        std::string tostring() const {
            return "position : " + _positionNode->tostring() + " ||" + "taille : " + _tailleNode->tostring();
        }

    Position center() const {
        int cX = _positionNode->pos().x() + _tailleNode->width();
        int cY = _positionNode->pos().y() + _tailleNode->height();

        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode() override{
        return "<rect" +
            _positionNode->analyseCode() +
            _tailleNode->analyseCode() +
            FigureNode::analyseCode() +
            "/>\n";
    }
};

class DeclarationVariable: public Noeud {
    private: 
        std::string _nomVariable;
        FigureNode * _valueNode;

    public:
        DeclarationVariable(std::string const & nomVariable, FigureNode * valueNode):
            Noeud(),
            _nomVariable(nomVariable),
            _valueNode(valueNode)
        {}

        std::string nomVariable() const {
            return _nomVariable;
        }

        FigureNode * value() const {
            return _valueNode;
        }

        std::string analyseCode() override{
            if(CarreNode * c = dynamic_cast<CarreNode *>(_valueNode)){
                return c->analyseCode();
            }

            return "";
        }
};


class AccesFigureNode: public Noeud {
    public:
        virtual ~AccesFigureNode() = default;
};

class AccesIndexNode: public AccesFigureNode {
    private:
        FigureTypes _type;
        int _index;

    public:
        AccesIndexNode(FigureTypes type, int index):
            AccesFigureNode(), _type(type), _index(index){}

        FigureTypes type() const {
            return _type;
        }

        int index() const {
            return _index;
        }

        std::string analyseCode() {
            return "";
        }
};

class AccesVariableNode: public AccesFigureNode {
    private:
        std::string _varName;

    public:
        AccesVariableNode(std::string varName):
            AccesFigureNode(), _varName(varName){}

        std::string varName() const {
            return _varName;
        }

        std::string analyseCode() override{
            return "";
        }
};



class ModificationNode: public Noeud {
    private:
    
        AccesFigureNode * _accesFigure;
        FigureNode * _figure;
        std::string _attribut;
        std::string _value;

    public:
        ModificationNode(AccesFigureNode * accesFigure, std::string attribut, std::string value):
            Noeud(), _accesFigure(accesFigure), _figure(nullptr), _attribut(attribut), _value(value){}


        std::string analyseCode() override {
            if(_figure != nullptr){
                _figure->setAttribut(_attribut, _value);
            }

            return "";
        }

        void setFigure(FigureNode * figure) {
            _figure = figure;
        }

        AccesFigureNode * getAccesFigureNode() const {
            return _accesFigure;
        }
};


class ConditionNode: public Noeud {
    public:
        virtual ~ConditionNode() = default;
        virtual bool evaluate() const = 0;
};


class ValeurNumeriqueNode: public Noeud {
    public:
        ~ValeurNumeriqueNode() = default;
        virtual float value() const = 0;
};




class ConstanteNumeriqueNode: public ValeurNumeriqueNode {
    private:
        float _val;

    public:
        ConstanteNumeriqueNode(float val):
            ValeurNumeriqueNode(), _val(val){}

        float value() const override {
            return _val;
        }
};

class AccesAttributNumerique: public ValeurNumeriqueNode {
    private:
        FigureNode * _figure;
        std::string _attribut;

    public:
        AccesAttributNumerique(FigureNode * figure, std::string attribut):
            ValeurNumeriqueNode(), _figure(figure), _attribut(attribut){}

        float value() const override {
            return _figure->getAttributNumberValue(_attribut);
        }
};


class ValeurStringNode: public Noeud {
    public:
        ~ValeurStringNode() = default;
        virtual std::string value() const = 0;
};



class ConstanteStringNode: public ValeurStringNode {
    private:
        std::string _val;

    public:
        ConstanteStringNode(std::string val):
            ValeurStringNode(), _val(val){}

        std::string value() const override {
            return _val;
        }
};



class AccesCouleurFigure {
    private:
        AccesFigureNode * _accesFigure;
        std::string _couleur;

    public:
        AccesCouleurFigure(AccesFigureNode * accesFigure):
            _accesFigure(accesFigure){}

        void setColor(std::string couleur) {
            _couleur = couleur;
        }

        std::string value() const {
            return _couleur;
        }

        AccesFigureNode * accesFigure() const {
            return _accesFigure;
        }
};



class CouleurConditionNode: public ConditionNode {
    private:
        AccesCouleurFigure * _val1;
        string_operators _operateur;
        std::string _val2;

    public:

        CouleurConditionNode(AccesCouleurFigure * val1, string_operators operateur, std::string val2):
            ConditionNode(), 
            _val1(val1), 
            _operateur(operateur), 
            _val2(val2)
        {}


        bool evaluate() const {
            switch(_operateur){
                std::cout<<"val1 : "<<_val1->value()<<" ||" <<_val2<<"\n";
                case string_operators::equal:
                    return _val1->value() == _val2;
                
                case string_operators::not_equal:
                    return _val1->value() != _val2;
            }

            return false;
        }

        std::string analyseCode() override {
            return "";
        }

        AccesCouleurFigure * getAccesCouleurFigure() const {
            return _val1;
        }
};





class NumberConditionNode: public ConditionNode {
    private:
        ValeurNumeriqueNode * _nb1;
        operators _operateur;
        ValeurNumeriqueNode * _nb2;

    public:
        NumberConditionNode(ValeurNumeriqueNode * nb1, operators operateur, ValeurNumeriqueNode * nb2):
            ConditionNode(), 
            _nb1(nb1), 
            _operateur(operateur), 
            _nb2(nb2)
        {}

        bool evaluate() const {
            switch(_operateur){
                case operators::equal:
                    return _nb1->value() == _nb2->value();
                
                case operators::not_equal:
                    return _nb1->value() != _nb2->value();

                case operators::greater:
                    return _nb1->value() > _nb2->value();

                case operators::greater_equal:
                    return _nb1->value() >= _nb2->value();

                case operators::less:
                    return _nb1->value() < _nb2->value();

                case operators::less_equal:
                    return _nb1->value() <= _nb2->value();
            }

            return false;
        }

        std::string analyseCode() override{
            return "";
        }
};


class CanevaNode: public SizeNode {
    public:
        CanevaNode(int w, int h):
            SizeNode(w, h){}
};

class ArbreSyntaxique {
    protected:
        std::vector<Noeud *> _arbre;

    public:
        ArbreSyntaxique() = default;

        void addNode(Noeud * node){
            if (CanevaNode* c = dynamic_cast<CanevaNode*>(node)){
                CanevaNode* caneva = getCanevaNode();
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

        std::vector<Noeud *> getArbre() const {
            return _arbre;
        }

        CanevaNode * getCanevaNode(bool deleteCaneva = false) const {
            for(auto noeud: _arbre){
                if (CanevaNode* caneva = dynamic_cast<CanevaNode*>(noeud)){
                    return caneva;
                }
            }

            return nullptr;
        }

        FigureNode * accesFigureIndex(int index, FigureTypes figureType) const;
        FigureNode * accesVariableValue(std::string const & varName) const;
        void setAttributVariableFigure(FigureNode * figure, std::string const & attribut, std::string const & value) const;

        std::string analyseCode();
        std::string analyseNodes(std::vector<Noeud *> nodes);
};




class NoeudInterne: public Noeud {
    private:
        std::vector<Noeud *> _instructions;

    public:
        NoeudInterne(std::vector<Noeud *> instructions):
            Noeud(), _instructions(instructions){}

        std::vector<Noeud *> instructions() const {
            return _instructions;
        }

        std::string analyseCode() override{
            return "";
        }
};


class IfNode: public NoeudInterne {
    private:
        ConditionNode * _condition;

    public:
        IfNode(std::vector<Noeud *> instructions, ConditionNode * condition):
            NoeudInterne(instructions),
            _condition(condition)
        {}

        bool evaluate() const {
            return _condition->evaluate();
        }

        ConditionNode * condition() const {
            return _condition;
        }
};



class WhileNode: public NoeudInterne {
    private:
        ConditionNode * _condition;

    public:
        WhileNode(std::vector<Noeud *> instructions, ConditionNode * condition):
            NoeudInterne(instructions),
            _condition(condition)
        {}
};

class ForLoopNode: public NoeudInterne {
    private:
        int _i;

    public:
        ForLoopNode(std::vector<Noeud *> instructions, int i):
            NoeudInterne(instructions),
            _i(i)
        {}
};