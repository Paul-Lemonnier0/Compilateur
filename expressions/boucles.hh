
#pragma once

#include "condition.hh"
#include "noeud.hh"



class WhileNode: public NoeudInterne {
    private:
        std::vector<std::shared_ptr<ConditionNode>> _conditions;

    public:
        WhileNode(std::vector<std::shared_ptr<Noeud>> instructions, std::vector<std::shared_ptr<ConditionNode>> conditions):
            NoeudInterne(instructions),
            _conditions(conditions)
        {}

        std::vector<std::shared_ptr<ConditionNode>> getConditions() const {
            return _conditions;
        }

        bool evaluate(Contexte & contexte) const {
            for(auto condition: _conditions){
                if(!condition->evaluate(contexte)){
                    return false;
                }
            }
            
            return true;
        }
};

class ForLoopNode: public NoeudInterne {
    private:
        ExpressionPtr _i;

    public:
        ForLoopNode(std::vector<std::shared_ptr<Noeud>> instructions, ExpressionPtr i):
            NoeudInterne(instructions),
            _i(i)
        {}

        ExpressionPtr compteur() const {
            return _i;
        }
};