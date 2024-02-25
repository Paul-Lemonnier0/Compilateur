#include "noeud.hh"
#include <algorithm>

class Couleur {
    public:
        virtual std::string getCouleur(Contexte & contexte) const = 0;
};

using CouleurPtr = std::shared_ptr<Couleur>;

class CouleurConstante: public Couleur {
    private:
        std::string _value;

    public:
        CouleurConstante(std::string value):
            _value(value) {}

        std::string getCouleur(Contexte & contexte) const override {
            return _value;
        }
};

class CouleurVariable: public Couleur {
    private:
        std::string _varName;

    public:
        CouleurVariable(std::string varName):
            _varName(varName) {}

        std::string getCouleur(Contexte & contexte) const override {
            return contexte.getStringVar(_varName);
        }
};


class CouleurTrad {
    private:
        std::map<std::string, std::string> _english {
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

    public:
        CouleurTrad() = default;

        std::string TranslateToEnglish(std::string couleur) const {
            if(_english.count(couleur)){
                return _english.at(couleur);
            }

            return couleur;
        }
};



class AttributNode: public NoeudInterpretable {
    public:
        ~AttributNode() = default;

        virtual std::string type() const  = 0;
};



class ColorAttributNode : public AttributNode {
    protected:
        CouleurPtr _value;

    public:
        ColorAttributNode(CouleurPtr value):
            AttributNode(), _value(value) {}

        void set(CouleurPtr value) {
            _value = value;
        }

        CouleurPtr value() const {
            return _value;
        }
};


class ColorNode: public ColorAttributNode {
    public:
        ColorNode(CouleurPtr couleur):
            ColorAttributNode(couleur){}

        ColorNode():
            ColorAttributNode(std::make_shared<CouleurConstante>("noir")){}

        std::string type() const override { return "couleur"; }

        std::string analyseCode(Contexte & contexte) {
            CouleurTrad couleur_trad;
            std::string couleur = _value->getCouleur(contexte);

            std::transform(couleur.begin(), couleur.end(), couleur.begin(), [](unsigned char c) {
                return std::tolower(c);
            });

            return " stroke=\"" + couleur_trad.TranslateToEnglish(couleur) + "\" ";
        }
};

class RemplissageNode: public ColorAttributNode {
    public:
        RemplissageNode(CouleurPtr couleur):
            ColorAttributNode(couleur){}

        RemplissageNode():
            ColorAttributNode(std::make_shared<CouleurConstante>("none")){}

        std::string type() const override { return "remplissage"; }

        std::string analyseCode(Contexte & contexte) {
            CouleurTrad couleur_trad;
            std::string couleur = _value->getCouleur(contexte);

            return " fill=\"" + couleur_trad.TranslateToEnglish(couleur) + "\" ";
        }
};


class NumericAttributNode : public AttributNode {
    protected:
        ExpressionPtr _value;

    public:
        NumericAttributNode(ExpressionPtr value):
            AttributNode(), _value(value) {}

        ExpressionPtr getValue() { return _value;}

        void set(ExpressionPtr value) {
            _value = value;
        }

        double value(Contexte & contexte) const {
            return _value->calculer(contexte);
        }
};

class RotationNode: public NumericAttributNode {
    public:
        RotationNode(ExpressionPtr rotation):
            NumericAttributNode(rotation) {}

        RotationNode():
            NumericAttributNode(std::make_shared<Constante>(0)) {}

        std::string type() const override { return "rotation"; }

        std::string analyseCode(Contexte & contexte) {
            return " transform=\"rotate(" + std::to_string(_value->calculer(contexte));
        }
};

class OpaciteNode: public NumericAttributNode {
    public:
        OpaciteNode(ExpressionPtr opacite):
            NumericAttributNode(opacite) {}

        OpaciteNode():
            NumericAttributNode(std::make_shared<Constante>(100)) {}

        std::string type() const override { return "opacite"; }

        std::string analyseCode(Contexte & contexte) {
            return " opacity=\"" + std::to_string(_value->calculer(contexte) / 100) + "\" ";
        }
};

class EpaisseurNode: public NumericAttributNode {
    public:
        EpaisseurNode(ExpressionPtr epaisseur):
            NumericAttributNode(epaisseur) {}

        EpaisseurNode():
            NumericAttributNode(std::make_shared<Constante>(1)) {}

        std::string type() const override { return "epaisseur"; }

        std::string analyseCode(Contexte & contexte) {
            return " stroke-width=\"" + std::to_string(_value->calculer(contexte)) + "\" ";
        }
};

class PositionXNode: public NumericAttributNode {
    private:
        std::string _attribut;
    public:
        PositionXNode(std::string x,ExpressionPtr valX):
            NumericAttributNode(valX), _attribut(x) {}

        PositionXNode():
            NumericAttributNode(std::make_shared<Constante>(0)) {}

        std::string type() const override { return "positionx"; }

        std::string attribut() { return _attribut; }

        std::string analyseCode(Contexte & contexte) {
            if(_attribut.length() == 9)
                return " x=\"" + std::to_string(_value->calculer(contexte)) + "\" ";
            else 
                return " x" + std::to_string(_attribut[9]) + "=\"" + std::to_string(_value->calculer(contexte)) + "\" ";
            
        }
};

class PositionYNode: public NumericAttributNode {
    private:
        std::string _attribut;
    public:
        PositionYNode(std::string y,ExpressionPtr valY):
            NumericAttributNode(valY), _attribut(y) {}

        PositionYNode():
            NumericAttributNode(std::make_shared<Constante>(0)) {}

        std::string type() const override { return "positiony"; }

        std::string attribut() { return _attribut; }

        std::string analyseCode(Contexte & contexte) {
            if(_attribut.length() == 9)
                return " y=\"" + std::to_string(_value->calculer(contexte)) + "\" ";
            else 
                return " y" + std::to_string(_attribut[9]) + "=\"" + std::to_string(_value->calculer(contexte)) + "\" ";
            
        }
};