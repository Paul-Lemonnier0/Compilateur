
#pragma once

#include "noeud.hh"

class ConditionNode: public Noeud {
    public:
        virtual ~ConditionNode() = default;
        virtual bool evaluate(Contexte & contexte) const = 0;

        static bool evaluateString(string_operators op, std::string str1, std::string str2) {
                switch(op){
                    case string_operators::equal:
                        return str1 == str2;
                    
                    case string_operators::not_equal:
                        return str1 != str2;
                }

                return false;
        }

        static bool evaluateNumbers(operators op, double val1, double val2) {
            switch(op){
                case operators::equal:
                    return val1 == val2;
                
                case operators::not_equal:
                    return val1 != val2;

                case operators::greater:
                    return val1 > val2;

                case operators::greater_equal:
                    return val1 >= val2;

                case operators::less:
                    return val1 < val2;

                case operators::less_equal:
                    return val1 <= val2;
            }

            return false;
        }
};

class FigureConditionNode: public ConditionNode {
    protected:
        std::shared_ptr<AccesFigureNode> _val1;
        std::shared_ptr<FigureNode> _fig;

    public:
        FigureConditionNode(std::shared_ptr<AccesFigureNode> val1):
            ConditionNode(),
            _val1(val1),
            _fig(nullptr) {}

        std::shared_ptr<AccesFigureNode> getAccesFigureNode() {
            return _val1;
        }

        void setFigure(std::shared_ptr<FigureNode> fig){
            _fig = fig;
        }

};

class CouleurConditionNode: public FigureConditionNode {
    private:
        string_operators _operateur;
        CouleurPtr _val2;

    public:

        CouleurConditionNode(std::shared_ptr<AccesFigureNode> val1, string_operators operateur, CouleurPtr val2):
            FigureConditionNode(val1), 
            _operateur(operateur), 
            _val2(val2)
        {}

        bool evaluate(Contexte & contexte) const {
            if(_fig != nullptr){
                return ConditionNode::evaluateString(_operateur, _fig->getCouleur(contexte), _val2->getCouleur(contexte));
            }

            return false;
        }
};

class NumberConditionNode: public ConditionNode {
    private:
        ExpressionPtr _val1;
        operators _operateur;
        ExpressionPtr _val2;

    public:

        NumberConditionNode(ExpressionPtr val1, operators operateur, ExpressionPtr val2):
            _val1(val1), 
            _operateur(operateur), 
            _val2(val2)
        {}

        bool evaluate(Contexte & contexte) const {
            double val1 = _val1->calculer(contexte);
            double val2 = _val2->calculer(contexte);

            return ConditionNode::evaluateNumbers(_operateur, val1, val2);
        }
};


class TailleConditionNode: public FigureConditionNode {
    private:
        operators _operateur;
        ExpressionPtr _val2;
        TailleType _tailleType;

    public:
        TailleConditionNode(std::shared_ptr<AccesFigureNode> val1, operators operateur, ExpressionPtr val2, TailleType tailleType):
            FigureConditionNode(val1), 
            _operateur(operateur), 
            _val2(val2),
            _tailleType(tailleType)
        {}

        bool evaluate(Contexte & contexte) const {
            if(_fig != nullptr) {
                double val2 = _val2->calculer(contexte);

                if(std::shared_ptr<FG_TailleUniforme> uniformeFig = std::dynamic_pointer_cast<FG_TailleUniforme>(_fig)){
                    double taille = uniformeFig->getTaille()->calculer(contexte);
                    return ConditionNode::evaluateNumbers(_operateur, taille, val2);
                }
                
                else if (_tailleType != TailleType::taille) {
                    if(std::shared_ptr<FG_TailleNonUniforme> nonUniformeFig = std::dynamic_pointer_cast<FG_TailleNonUniforme>(_fig)){
                        if(_tailleType == TailleType::hauteur){
                            double hauteur = nonUniformeFig->getHeight()->calculer(contexte);
                            return ConditionNode::evaluateNumbers(_operateur, hauteur, val2);
                        }

                        else {
                            double largeur = nonUniformeFig->getWidth()->calculer(contexte);
                            return ConditionNode::evaluateNumbers(_operateur, largeur, val2);
                        }
                    }
                }
            }

            return false;
        }
};


class BooleanVariableConditionNode: public ConditionNode {
    private:
        std::string _varName;

    public:
        BooleanVariableConditionNode(std::string varName):
            ConditionNode(), _varName(varName) {}

        bool evaluate(Contexte & contexte) const {
            return contexte.getBoolVar(_varName);
        }
};


class IfNode: public NoeudInterne {
    private:
        std::vector<std::shared_ptr<Noeud>> _elseInstructions;
        std::vector<std::shared_ptr<ConditionNode>> _conditions;

    public:
        IfNode(std::vector<std::shared_ptr<Noeud>> instructions, std::vector<std::shared_ptr<Noeud>> elseInstructions, std::vector<std::shared_ptr<ConditionNode>> conditions):
            NoeudInterne(instructions),
            _elseInstructions(elseInstructions),
            _conditions(conditions)
        {}

        bool evaluate(Contexte & contexte) const {
            for(auto condition: _conditions){
                if(!condition->evaluate(contexte)){
                    return false;
                }
            }

            return true;
        }

        std::vector<std::shared_ptr<ConditionNode>> conditions() const {
            return _conditions;
        }

        std::vector<std::shared_ptr<Noeud>> elseInstructions() const {
            return _elseInstructions;
        }
};

class PositionConditionNode: public FigureConditionNode {
    private:
        operators _operateur;
        ExpressionPtr _val2;
        std::string _position;

    public:

        PositionConditionNode(std::shared_ptr<AccesFigureNode> val1, std::string position, operators operateur, ExpressionPtr val2):
            FigureConditionNode(val1), 
            _operateur(operateur), 
            _val2(val2),
            _position(position)
        {}

        std::shared_ptr<AccesFigureNode> getAccesFigureNode() {
            return _val1;
        }

        void setFigure(std::shared_ptr<FigureNode> fig){
            _fig = fig;
        }

        bool evaluate(Contexte & contexte) const override {
            if(_fig != nullptr){
                double val2 = _val2->calculer(contexte);

                int nombre = 0;
                if(_position.length() == 10) //ou avec un stoi ici
                    nombre = _position[9]-48;

                if(_position[8] == 'X') {
                    double positionX = _fig->getPositionX(nombre)->calculer(contexte);
                    return ConditionNode::evaluateNumbers(_operateur, positionX, val2);
                }
                else {
                    double positionY = _fig->getPositionY(nombre)->calculer(contexte);
                    return ConditionNode::evaluateNumbers(_operateur, positionY, val2);
                }
            }

            return false;
        }
};