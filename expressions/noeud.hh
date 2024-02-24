#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>
#include "contexte.hh"
#include "expressionBinaire.hh"
#include "expressionUnaire.hh"
#include "constante.hh"
#include "variable.hh"
#include <iostream>

enum class FigureTypes {
    carre,
    rectangle,
    triangle,
    cercle,
    chemin,
    ellipse,
    ligne,
    texte
};

enum class operators { equal, not_equal, less_equal, greater_equal, less, greater };
enum class string_operators { equal, not_equal };

class Noeud {
    public:
        virtual ~Noeud() = default;

        virtual std::string analyseCode(Contexte & contexte) = 0;
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

        std::string analyseCode(Contexte & contexte) {
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

        std::string analyseCode(Contexte & contexte) override{
            return "";
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

class AffectationSimpleVariableNode: public Noeud {
    protected:
        std::string _varName;

    public:
        AffectationSimpleVariableNode(std::string name):
            Noeud(), _varName(name) {}

        std::string analyseCode(Contexte & contexte) override {
            return "";
        }

        virtual void setVariable(Contexte & contexte) const = 0;
};

class AffectationDoubleVariableNode: public AffectationSimpleVariableNode {
    private:
        ExpressionPtr _value;

    public:
        AffectationDoubleVariableNode(std::string name, ExpressionPtr value):
            AffectationSimpleVariableNode(name), _value(value) {}

        void setVariable(Contexte & contexte) const {
            double val = _value->calculer(contexte);
            contexte[_varName] = val;
        }
};

class AffectationBoolVariableNode: public AffectationSimpleVariableNode {
    private:
        bool _value;

    public:
        AffectationBoolVariableNode(std::string name, bool value):
            AffectationSimpleVariableNode(name), _value(value) {}

        void setVariable(Contexte & contexte) const {
            contexte.setBoolVar(_varName, _value);
        }
};

class AffectationCouleurVariableNode: public AffectationSimpleVariableNode {
    private:
        std::string _value;

    public:
        AffectationCouleurVariableNode(std::string name, std::string value):
            AffectationSimpleVariableNode(name), _value(value) {}

        void setVariable(Contexte & contexte) const {
            contexte.setStringVar(_varName, _value);
        }
};

class NoeudInterne: public Noeud {
    private:
        std::vector<std::shared_ptr<Noeud>> _instructions;

    public:
        NoeudInterne(std::vector<std::shared_ptr<Noeud>> instructions):
            Noeud(), _instructions(instructions){}

        std::vector<std::shared_ptr<Noeud>> instructions() const {
            return _instructions;
        }

        std::string analyseCode(Contexte & contexte) override{
            return "";
        }
};


class DeclarationVariableSimple: public Noeud {
    protected:
        std::string _name;

    public:
        DeclarationVariableSimple(std::string name):
            _name(name){}

        std::string analyseCode(Contexte & contexte) override {
            return "";
        }

        std::string const & nom() const {
            return _name;
        }

        virtual void createVariable(Contexte & contexte) = 0;
};


class DeclarationVariableInt: public DeclarationVariableSimple {
    private:
        ExpressionPtr _val;

    public:
        DeclarationVariableInt(std::string name, ExpressionPtr val):
            DeclarationVariableSimple(name), _val(val) {}

        void createVariable(Contexte & contexte) override {
            double v = _val->calculer(contexte);
            contexte.setDoubleVar(_name, v);
        }
};

class DeclarationVariableBool: public DeclarationVariableSimple {
    private:
        bool _val;

    public:
        DeclarationVariableBool(std::string name, bool val):
            DeclarationVariableSimple(name), _val(val) {}

        void createVariable(Contexte & contexte) override {
            contexte.setBoolVar(_name, _val);
        }
};

class DeclarationVariableString: public DeclarationVariableSimple {
    private:
        std::string _val;

    public:
        DeclarationVariableString(std::string name, std::string val):
            DeclarationVariableSimple(name), _val(val) {}

        void createVariable(Contexte & contexte) override {
            contexte.setStringVar(_name, _val);
        }
};