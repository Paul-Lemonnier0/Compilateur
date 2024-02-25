#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>

#include "expression.hh"
#include "noeud.hh"
#include "attribut.hh"
#include <map>

class Position {
    private:
        ExpressionPtr _x, _y;

    public:
        Position(ExpressionPtr x, ExpressionPtr y): 
            _x(x), _y(y) {};

        Position(Position const & p) = default;

        ExpressionPtr x() const { return _x; }

        ExpressionPtr y() const { return _y; }

        std::string toSVG(const Contexte & contexte) const {
            double x = _x->calculer(contexte);
            double y = _y->calculer(contexte);

            return "x=\"" + std::to_string(x) + "\" y=\"" + std::to_string(y) + "\"";
        }

        std::string toString(const Contexte & contexte) const {
            double x = _x->calculer(contexte);
            double y = _y->calculer(contexte);

            return std::to_string(x) + "," + std::to_string(y);
        }
};

class PositionNode: public NoeudInterpretable {
    private:
        Position _p;

    public:
        PositionNode(ExpressionPtr x, ExpressionPtr y):
            _p(x, y){}

        std::string tostring() const {
            return "position string";
        }

        std::string analyseCode(Contexte & contexte) override{
            return _p.toSVG(contexte);
        }

        Position pos() const {
            return _p;
        }
};

class TailleNode: public NoeudInterpretable {
    private:
        ExpressionPtr _w, _h;

    public:
        TailleNode(ExpressionPtr w, ExpressionPtr h):
            _w(w), _h(h) {}

        TailleNode(ExpressionPtr size):
            _w(size), _h(size) {}

        double width(const Contexte & contexte) const {
            return _w->calculer(contexte);
        }

        double height(const Contexte & contexte) const {
            return _h->calculer(contexte);
        }

        std::string analyseCode(Contexte & contexte) override{
            return " width=\"" + std::to_string(width(contexte)) 
                + "\" height=\"" + std::to_string(height(contexte)) + "\"";
        }

        ExpressionPtr width() const { return _w; }

        ExpressionPtr height() const { return _h; }

        void setWidth(ExpressionPtr w) { _w = w; }

        void setHeight(ExpressionPtr h) { _h = h; }
};


class CanevaNode: public TailleNode {
    public:
        CanevaNode(ExpressionPtr w, ExpressionPtr h):
            TailleNode(w, h){}
};

class FigureNode: public NoeudInterpretable {
    private:

        std::shared_ptr<ColorNode> _couleur;
        std::shared_ptr<RotationNode> _rotation;
        std::shared_ptr<OpaciteNode> _opacite;
        

    public:
        FigureNode():
            _couleur(std::make_shared<ColorNode>()),
            _rotation(std::make_shared<RotationNode>()),
            _opacite(std::make_unique<OpaciteNode>())
        {}

        std::string getCouleur(Contexte & contexte) const{
            return _couleur->value()->getCouleur(contexte);
        }

        std::shared_ptr<ColorNode> getcouleur() const {
            return _couleur;
        }
        std::shared_ptr<RotationNode> getrotation() const {
            return _rotation;
        }

        std::shared_ptr<OpaciteNode> getopacite() const {
            return _opacite;
        }
        void setCouleur(std::shared_ptr<ColorNode> c) {
            _couleur = c;
        }
        void setRotation(std::shared_ptr<RotationNode> r) {
            _rotation = r;
        }
        void setOpacite(std::shared_ptr<OpaciteNode> o) {
            _opacite = o;
        }
        virtual void setAttributs(std::vector<std::shared_ptr<AttributNode>> attributs) = 0;
        virtual void setAttribut(std::shared_ptr<AttributNode> attribut) = 0;
        virtual Position center(Contexte & contexte) const = 0;
        virtual ExpressionPtr getPositionX(int position) = 0;
        virtual ExpressionPtr getPositionY(int position) = 0;
};

class FormeGeometrique : public FigureNode {
    protected : 
        std::shared_ptr<RemplissageNode> _remplissage;
        std::shared_ptr<EpaisseurNode> _epaisseur;
        std::shared_ptr<PositionNode> _positionNode;
    public :
        FormeGeometrique(std::shared_ptr<PositionNode> positionNode):
            FigureNode(),
            _remplissage(std::make_shared<RemplissageNode>()),
            _epaisseur(std::make_shared<EpaisseurNode>()),
            _positionNode(positionNode)
            {}

        std::shared_ptr<PositionNode> positionNode() { return _positionNode;}
        void setPosition(std::shared_ptr<PositionNode> p) { _positionNode = p;}

        ExpressionPtr getPositionX(int position) override {
            return _positionNode->pos().x();
        }

        virtual void setPositionX(std::shared_ptr<PositionXNode> positionX) {
            if(positionX->attribut().length()==9)
                _positionNode =  std::make_shared<PositionNode>(positionX->getValue(),_positionNode->pos().y());
        }

        ExpressionPtr getPositionY(int position) override {
            return _positionNode->pos().y();
        }

        virtual void setPositionY(std::shared_ptr<PositionYNode> positionY) {
            if(positionY->attribut().length()==9)
                _positionNode = std::make_shared<PositionNode>(_positionNode->pos().x(),positionY->getValue());
        }

        void setAttributs(std::vector<std::shared_ptr<AttributNode>> attributs) override{
            for(const auto& attribut : attributs)
            {
                setAttribut(attribut);
            }
        }

        void setAttribut(std::shared_ptr<AttributNode> attribut) override{
            if(std::shared_ptr<ColorNode> colorNode = std::dynamic_pointer_cast<ColorNode>(attribut)){
                setCouleur(colorNode);
            }

            else if(std::shared_ptr<RemplissageNode> remplissageNode = std::dynamic_pointer_cast<RemplissageNode>(attribut)){
                _remplissage = remplissageNode;
            }

            else if(std::shared_ptr<OpaciteNode> opaciteNode =  std::dynamic_pointer_cast<OpaciteNode>(attribut)){
                setOpacite(opaciteNode);
            }

            else if(std::shared_ptr<EpaisseurNode> epaisseurNode =  std::dynamic_pointer_cast<EpaisseurNode>(attribut)){
                _epaisseur = epaisseurNode;
            }

            else if(std::shared_ptr<RotationNode> rotationNode =  std::dynamic_pointer_cast<RotationNode>(attribut)){
                setRotation(rotationNode);
            }

            else if(std::shared_ptr<PositionXNode> positionX = std::dynamic_pointer_cast<PositionXNode>(attribut)){
                setPositionX(positionX);
            }
            
            else if(std::shared_ptr<PositionYNode> positionY = std::dynamic_pointer_cast<PositionYNode>(attribut)){
                setPositionY(positionY);
            }
        }

        std::string analyseCode(Contexte & contexte) override{

            return getcouleur()->analyseCode(contexte) +
                   _remplissage->analyseCode(contexte) +
                   getopacite()->analyseCode(contexte) +
                   _epaisseur->analyseCode(contexte) +
                   getrotation()->analyseCode(contexte) +
                   "," + center(contexte).toString(contexte) + ")\"";
        }


};


class FormeGeometriqueAvecTaille: public FormeGeometrique {
    protected:
        std::shared_ptr<TailleNode> _tailleNode;

    public:
        FormeGeometriqueAvecTaille(std::shared_ptr<PositionNode> positionNode, ExpressionPtr size):    
            FormeGeometrique(positionNode), _tailleNode(std::make_shared<TailleNode>(size)) {}

        FormeGeometriqueAvecTaille(std::shared_ptr<PositionNode> positionNode, ExpressionPtr w, ExpressionPtr h):    
            FormeGeometrique(positionNode), _tailleNode(std::make_shared<TailleNode>(w, h)) {}

        ExpressionPtr getHeight() const {
            return _tailleNode->height();
        }

        ExpressionPtr getWidth() const {
            return _tailleNode->width();
        }
}; 

class FG_TailleUniforme: public FormeGeometriqueAvecTaille {
    public:
        FG_TailleUniforme(std::shared_ptr<PositionNode> positionNode, ExpressionPtr size):
            FormeGeometriqueAvecTaille(positionNode, size) {}

        void setTaille(ExpressionPtr newVal) {
            _tailleNode->setWidth(newVal);
            _tailleNode->setHeight(newVal);
        }

        ExpressionPtr getTaille() const {
            return _tailleNode->width();
        }
};

class FG_TailleNonUniforme: public FormeGeometriqueAvecTaille {
    public:
        FG_TailleNonUniforme(std::shared_ptr<PositionNode> positionNode, ExpressionPtr w, ExpressionPtr h):    
            FormeGeometriqueAvecTaille(positionNode, w,h) {}

        void setHeight(ExpressionPtr newVal) {
            _tailleNode->setHeight(newVal);
        }

        void setWidth(ExpressionPtr newVal) {
            _tailleNode->setWidth(newVal);
        }

        ExpressionPtr getHeight() const {
            return _tailleNode->height();
        }

        ExpressionPtr getWidth() const {
            return _tailleNode->width();
        }
};


class CarreNode: public FG_TailleUniforme{
    public:
        CarreNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr size):
            FG_TailleUniforme(std::make_shared<PositionNode>(x, y), size) 
        {}


    Position center(Contexte & contexte) const override {
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_positionNode->pos().x(), _tailleNode->width(),OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_positionNode->pos().y(), _tailleNode->height(),OperateurBinaire::plus);
        
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        return "<rect " +
            _positionNode->analyseCode(contexte) +
            _tailleNode->analyseCode(contexte) +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }
};
class RectangleNode: public FormeGeometrique{
    private:
        std::shared_ptr<PositionNode> _p2, _p3, _p4;
        std::shared_ptr<TailleNode> _tailleNode;

    public:
        RectangleNode(ExpressionPtr x1,  ExpressionPtr y1,ExpressionPtr x2,  ExpressionPtr y2,ExpressionPtr x3,  ExpressionPtr y3,ExpressionPtr x4,  ExpressionPtr y4):
            FormeGeometrique(std::make_shared<PositionNode>(x1, y1)), 
            _p2(std::make_shared<PositionNode>(x2, y2)),
            _p3(std::make_shared<PositionNode>(x3, y3)),
            _p4(std::make_shared<PositionNode>(x4, y4)),
            _tailleNode(nullptr)
            {
                ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), positionNode()->pos().x(),OperateurBinaire::moins);
                ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), positionNode()->pos().y(),OperateurBinaire::moins);
            
                _tailleNode =std::make_shared<TailleNode>(cX,cY);
            }


    Position center(Contexte & contexte) const override {
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_positionNode->pos().x(), _tailleNode->width(),OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_positionNode->pos().y(), _tailleNode->height(),OperateurBinaire::plus);
        
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        return "<rect " +
            _positionNode->analyseCode(contexte) +
            _tailleNode->analyseCode(contexte) +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }

    void setPositionX(std::shared_ptr<PositionXNode> positionX) override {
        if(positionX->attribut().length()==10) {
            int numero = positionX->attribut()[9] - 48;
            if(numero == 1) {
                setPosition(std::make_shared<PositionNode>(positionX->getValue(),_positionNode->pos().y()));
                ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), _positionNode->pos().x(),OperateurBinaire::moins);
                ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), _positionNode->pos().y(),OperateurBinaire::moins);
            
                _tailleNode =std::make_shared<TailleNode>(cX,cY);
            }
            else if (numero == 2) {
                _p2 = std::make_shared<PositionNode>(positionX->getValue(),_p2->pos().y());
                }
            else if (numero == 3) {
                _p3 = std::make_shared<PositionNode>(positionX->getValue(),_p3->pos().y());
            }
            else if (numero == 4) {
                _p4 = std::make_shared<PositionNode>(positionX->getValue(),_p4->pos().y());
                ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), _positionNode->pos().x(),OperateurBinaire::moins);
                ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), _positionNode->pos().y(),OperateurBinaire::moins);
            
                _tailleNode =std::make_shared<TailleNode>(cX,cY);
            }
        }
    }

    void setPositionY(std::shared_ptr<PositionYNode> positionY) override {
        if(positionY->attribut().length()==10) {
            int numero = positionY->attribut()[9] - 48;
                if(numero == 1) {
                    setPosition(std::make_shared<PositionNode>(_positionNode->pos().x(),positionY->getValue()));
                    ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), _positionNode->pos().x(),OperateurBinaire::moins);
                    ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), _positionNode->pos().y(),OperateurBinaire::moins);
                
                    _tailleNode =std::make_shared<TailleNode>(cX,cY);
                }
                else if (numero == 2) {
                    _p2 = std::make_shared<PositionNode>(_p2->pos().x(),positionY->getValue());
                }
                else if (numero == 3) {
                    _p3 = std::make_shared<PositionNode>(_p3->pos().x(),positionY->getValue());
                }
                else if (numero == 4) {
                    _p4 = std::make_shared<PositionNode>(_p4->pos().x(),positionY->getValue());
                    ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), _positionNode->pos().x(),OperateurBinaire::moins);
                    ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), _positionNode->pos().y(),OperateurBinaire::moins);
                
                    _tailleNode = std::make_shared<TailleNode>(cX,cY);
                }
        }
    }

    ExpressionPtr getPositionX(int position) override {
        if(position == 1) {
            return _positionNode->pos().x();
        }
        else if(position == 2) {
            return _p2->pos().x();
        }
        else if(position == 3) {
            return _p3->pos().x();
        }
        return _p4->pos().x();
    }
    ExpressionPtr getPositionY(int position) override {
        if(position == 1) {
            return _positionNode->pos().y();
        }
        else if(position == 2) {
            return _p2->pos().y();
        }
        else if(position == 3) {
            return _p3->pos().y();
        }
        return _p4->pos().y();
        
    }
    
};

class TriangleNode: public FG_TailleNonUniforme{
    public:
        TriangleNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr w, ExpressionPtr h):
            FG_TailleNonUniforme(std::make_shared<PositionNode>(x,y), w,h)
        {}


    Position center(Contexte & contexte) const override {
        ExpressionPtr const_2 = std::make_shared<Constante>(2);
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_tailleNode->width(),const_2,OperateurBinaire::divise);
        cX = std::make_shared<ExpressionBinaire>(_positionNode->pos().x(),cX,OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_tailleNode->height(),const_2,OperateurBinaire::divise);
        cY = std::make_shared<ExpressionBinaire>(_positionNode->pos().y(),cY,OperateurBinaire::moins);
        Position c = Position(cX, cY);
        
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        double x1 = _positionNode->pos().x()->calculer(contexte);
        double y1 = _positionNode->pos().y()->calculer(contexte);

        double x2 = x1 + _tailleNode->width()->calculer(contexte);
        double x3 = x1 + _tailleNode->width()->calculer(contexte) / 2;
        double y3 = _positionNode->pos().y()->calculer(contexte) - _tailleNode->height()->calculer(contexte);

        return "<polygon points=\"" +
            std::to_string(x1) + "," +
            std::to_string(y1) + " " +

            std::to_string(x2) + "," +
            std::to_string(y1) + " " +

            std::to_string(x3) + "," +
            std::to_string(y3) + "\"" +
            _tailleNode->analyseCode(contexte) +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }
};
class CercleNode: public FG_TailleUniforme{
    public:
        CercleNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr r):
            FG_TailleUniforme(std::make_shared<PositionNode>(x,y), r)
        {}


    Position center(Contexte & contexte) const override {
        Position c = Position(_positionNode->pos().x(), _positionNode->pos().y());
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        double x = _positionNode->pos().x()->calculer(contexte);
        double y = _positionNode->pos().y()->calculer(contexte);
        double r = _tailleNode->width()->calculer(contexte);
        return "<circle cx=\"" +
            std::to_string(x) + "\" cy=\"" +
            std::to_string(y) + "\" r=\"" +
            std::to_string(r) + "\" " +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }
};
class EllipseNode: public FG_TailleNonUniforme{
    private:
        std::shared_ptr<TailleNode> _tailleNode;

    public:
        EllipseNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr w, ExpressionPtr h):
            FG_TailleNonUniforme(std::make_shared<PositionNode>(x,y), w, h)
        {}


    Position center(Contexte & contexte) const override {
        Position c = Position(_positionNode->pos().x(), _positionNode->pos().y());
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        double x = _positionNode->pos().x()->calculer(contexte);
        double y = _positionNode->pos().y()->calculer(contexte);
        double w = _tailleNode->width()->calculer(contexte);
        double h = _tailleNode->height()->calculer(contexte);
        return "<ellipse cx=\"" +
            std::to_string(x) + "\" cy=\"" +
            std::to_string(y) + "\" rx=\"" +
            std::to_string(w) + "\" ry=\"" +
            std::to_string(h) + "\" " +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }
};

class LigneNode: public FormeGeometrique{
    private:
        std::shared_ptr<PositionNode> _p2;

    public:
        LigneNode(ExpressionPtr x1,  ExpressionPtr y1,ExpressionPtr x2,  ExpressionPtr y2):
            FormeGeometrique(std::make_shared<PositionNode>(x1,y1)), 
            _p2(std::make_shared<PositionNode>(x2, y2))
        {}


    Position center(Contexte & contexte) const override {
        ExpressionPtr const_2 = std::make_shared<Constante>(2);

        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_positionNode->pos().x(), _p2->pos().x(), OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_positionNode->pos().y(), _p2->pos().y(), OperateurBinaire::plus);
        cX = std::make_shared<ExpressionBinaire>(cX,const_2,OperateurBinaire::divise);
        cY = std::make_shared<ExpressionBinaire>(cY,const_2,OperateurBinaire::divise);
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        double x1 = _positionNode->pos().x()->calculer(contexte);
        double y1 = _positionNode->pos().y()->calculer(contexte);
        double x2 = _p2->pos().x()->calculer(contexte);
        double y2 = _p2->pos().y()->calculer(contexte);


        return "<line x1=\"" +
            std::to_string(x1) + "\" y1=\"" +
            std::to_string(y1) + "\" x2=\"" +
            std::to_string(x2) + "\" y2=\"" +
            std::to_string(y2) + "\" " +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }

    void setPositionX(std::shared_ptr<PositionXNode> positionX) override {
        if(positionX->attribut().length()==10) {
            int numero = positionX->attribut()[9] - 48;
            if(numero == 1) {
                setPosition(std::make_shared<PositionNode>(positionX->getValue(),_positionNode->pos().y())); }
            else if (numero == 2) {
                _p2 = std::make_shared<PositionNode>(positionX->getValue(),_p2->pos().y()); }
        }
    }

    void setPositionY(std::shared_ptr<PositionYNode> positionY) override {
        if(positionY->attribut().length()==10) {
            int numero = positionY->attribut()[9] - 48;
            if(numero == 1) {
                setPosition(std::make_shared<PositionNode>(_positionNode->pos().x(),positionY->getValue())); }
            else if (numero == 2) {
                _p2 = std::make_shared<PositionNode>(_p2->pos().x(),positionY->getValue()); }
        }
    }

    ExpressionPtr getPositionX(int position) override {
        if(position == 1) {
            return _positionNode->pos().x();
        }
        return _p2->pos().x();
    }

    ExpressionPtr getPositionY(int position) override {
        if(position == 1) {
            return _positionNode->pos().y();
        }
        return _p2->pos().y();
    }
};
class CheminNode: public FormeGeometrique{
    private:
        std::vector<std::shared_ptr<PositionNode>> _vectPos;

    public:
        CheminNode(std::vector<std::shared_ptr<PositionNode>> v):
            FormeGeometrique(v[0])
        {
            for(auto p : v) {
                _vectPos.push_back(p);
            }
        }


    Position center(Contexte & contexte) const override {
        ExpressionPtr const_2 = std::make_shared<Constante>(2);
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_vectPos.front()->pos().x(), _vectPos.back()->pos().x(),OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_vectPos.front()->pos().y(), _vectPos.back()->pos().y(),OperateurBinaire::plus);
        cX = std::make_shared<ExpressionBinaire>(cX,const_2,OperateurBinaire::divise);
        cY = std::make_shared<ExpressionBinaire>(cY,const_2,OperateurBinaire::divise);
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        std::string toutes_les_lignes = "";
        double cX1 = _vectPos.front()->pos().x()->calculer(contexte);
        double cY1 = _vectPos.front()->pos().y()->calculer(contexte);
        for(auto i : _vectPos) {
            double cX2 = i->pos().x()->calculer(contexte);
            double cY2 = i->pos().y()->calculer(contexte);
            toutes_les_lignes +=  "<line x1=\"" +
            std::to_string(cX1) + "\" y1=\"" +
            std::to_string(cY1) + "\" x2=\"" +
            std::to_string(cX2) + "\" y2=\"" +
            std::to_string(cY2) + "\" " +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
            cX1 = cX2;
            cY1 = cY2;
        }
        return toutes_les_lignes;
    }

    void setPositionX(std::shared_ptr<PositionXNode> positionX) override {
        if(positionX->attribut().length()==10) {
            unsigned int numero = positionX->attribut()[9] - 48;
            _vectPos[numero-1] = std::make_shared<PositionNode>(positionX->getValue(),_vectPos[numero-1]->pos().y());
        }
    }

    void setPositionY(std::shared_ptr<PositionYNode> positionY) override {
        if(positionY->attribut().length()==10) {
            unsigned int numero = positionY->attribut()[9] - 48;
            _vectPos[numero-1] = std::make_shared<PositionNode>(_vectPos[numero-1]->pos().x(),positionY->getValue());
        }
    }

    ExpressionPtr getPositionX(int position) override {
        return _vectPos[position-1]->pos().x();    
    }

    ExpressionPtr getPositionY(int position) override {
        return _vectPos[position-1]->pos().y();
    }
};

class TexteNode: public FigureNode{
    private:
        std::shared_ptr<PositionNode> _positionNode;
        std::string _texte, _police;

    public:
        TexteNode(ExpressionPtr x, ExpressionPtr y, std::string texte, std::string police):
            FigureNode(), 
            _positionNode(std::make_shared<PositionNode>(x,y)),
            _texte(texte),
            _police(police)

        {
            _texte.erase(0,1);
            _texte.pop_back();
        }


    Position center(Contexte & contexte) const override {
        ExpressionPtr taille_texte = std::make_shared<Constante>(_texte.length());
        ExpressionPtr const_2 = std::make_shared<Constante>(2);
        taille_texte = std::make_shared<ExpressionBinaire>(taille_texte, const_2,OperateurBinaire::divise);
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_positionNode->pos().x(),taille_texte,OperateurBinaire::plus);
        Position c = Position(cX, _positionNode->pos().y());
        return c;
    }

    void setAttributs(std::vector<std::shared_ptr<AttributNode>> attributs) override{
        for(const auto& attribut : attributs)
        {
            setAttribut(attribut);
        }
    }

    void setAttribut(std::shared_ptr<AttributNode> attribut) override{
        if(std::shared_ptr<ColorNode> colorNode = std::dynamic_pointer_cast<ColorNode>(attribut)){
            setCouleur(colorNode);
        }

        else if(std::shared_ptr<OpaciteNode> opaciteNode = std::dynamic_pointer_cast<OpaciteNode>(attribut)){
            setOpacite(opaciteNode);
        }

        else if(std::shared_ptr<RotationNode> rotationNode = std::dynamic_pointer_cast<RotationNode>(attribut)){
            setRotation(rotationNode);
        }
        else if(std::shared_ptr<PositionXNode> positionX = std::dynamic_pointer_cast<PositionXNode>(attribut)){
            if(positionX->attribut().length()==9)
                _positionNode =  std::make_shared<PositionNode>(positionX->getValue(),_positionNode->pos().y());
        }
        else if(std::shared_ptr<PositionYNode> positionY = std::dynamic_pointer_cast<PositionYNode>(attribut)){
            if(positionY->attribut().length()==9)
                _positionNode = std::make_shared<PositionNode>(_positionNode->pos().x(),positionY->getValue());
        }
    }

    std::string analyseCode(Contexte & contexte) override{
        return "<text " +
            _positionNode->pos().toSVG(contexte) +
            " font-family=" +
            _police + 
            getcouleur()->analyseCode(contexte) +
            getopacite()->analyseCode(contexte) +
            getrotation()->analyseCode(contexte) +
            "," + center(contexte).toString(contexte) + ")\" >" +
            _texte + "</text> \n";

    }

    ExpressionPtr getPositionX(int position) override {
        return _positionNode->pos().x();
    }

    ExpressionPtr getPositionY(int position) override {
        return _positionNode->pos().y();
    }
};

class ModificationFigureNode: public Noeud {
    protected:
        std::shared_ptr<AccesFigureNode> _accesFigure;
        std::shared_ptr<FigureNode> _figure;

    public:
        ModificationFigureNode(std::shared_ptr<AccesFigureNode> accesFigure):
            Noeud(), _accesFigure(accesFigure), _figure(nullptr){}


        virtual void modificate(Contexte & contexte) = 0;

        void setFigure(std::shared_ptr<FigureNode> figure) {
            _figure = figure;
        }

        std::shared_ptr<AccesFigureNode> getAccesFigureNode() const {
            return _accesFigure;
        }
};

class ModificationAttributsNode: public ModificationFigureNode {
    private:
        std::shared_ptr<AttributNode> _attribut;

    public:
        ModificationAttributsNode(std::shared_ptr<AccesFigureNode> accesFigure, std::shared_ptr<AttributNode> attribut):
            ModificationFigureNode(accesFigure), _attribut(attribut){}


        void modificate(Contexte & contexte) override {
            if(_figure != nullptr){
                _figure->setAttribut(_attribut);
            }
        }
};

enum class TailleType {hauteur, largeur, taille};

class ModificationTailleFigureNode: public ModificationFigureNode {
    private:
        TailleType _typeTaille;
        ExpressionPtr _newValue;

    public:
        ModificationTailleFigureNode(std::shared_ptr<AccesFigureNode> accesFigure, TailleType type, ExpressionPtr newValue):
            ModificationFigureNode(accesFigure), _typeTaille(type), _newValue(newValue){}

        void modificate(Contexte & contexte) override {
            if(_figure != nullptr){
                    if(_typeTaille == TailleType::taille){
                        if(std::shared_ptr<FG_TailleUniforme> figure = std::dynamic_pointer_cast<FG_TailleUniforme>(_figure)){
                            figure->setTaille(_newValue);
                        }
                    }

                    else {
                        if(std::shared_ptr<FG_TailleNonUniforme> figure = std::dynamic_pointer_cast<FG_TailleNonUniforme>(_figure)){
                            if(_typeTaille == TailleType::hauteur){
                                figure->setHeight(_newValue);
                            }

                            else figure->setWidth(_newValue);
                        }
                    }
            }
        }
};

class DeclarationVariable: public NoeudInterpretable {
    private: 
        std::string _nomVariable;
        std::shared_ptr<FigureNode> _valueNode;

    public:
        DeclarationVariable(std::string const & nomVariable, std::shared_ptr<FigureNode> valueNode):
            _nomVariable(nomVariable),
            _valueNode(valueNode)
        {}

        std::string nomVariable() const {
            return _nomVariable;
        }

        std::shared_ptr<FigureNode> value() const {
            return _valueNode;
        }

        std::string analyseCode(Contexte & contexte) override{
            if(_valueNode != nullptr){
                return _valueNode->analyseCode(contexte);
            }

            return "";
        }
};

