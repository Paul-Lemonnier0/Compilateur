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

class PositionNode: public Noeud {
    private:
        Position _p;

    public:
        PositionNode(ExpressionPtr x, ExpressionPtr y):
            Noeud(), _p(x, y){}

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

class TailleNode: public Noeud {
    private:
        ExpressionPtr _w, _h;

    public:
        TailleNode(ExpressionPtr w, ExpressionPtr h):
            Noeud(), _w(w), _h(h) {}

        TailleNode(ExpressionPtr size):
            Noeud(), _w(size), _h(size) {}

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

class FigureNode: public Noeud {
    private:

        std::shared_ptr<ColorNode> _couleur;
        std::shared_ptr<RotationNode> _rotation;
        std::shared_ptr<OpaciteNode> _opacite;
        

    public:
        FigureNode():
            Noeud(),
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
};

class FormeGeometrique : public FigureNode {
    private : 
        std::shared_ptr<RemplissageNode> _remplissage;
        std::shared_ptr<EpaisseurNode> _epaisseur;
    public :
        FormeGeometrique():
            FigureNode(),
            _remplissage(std::make_shared<RemplissageNode>()),
            _epaisseur(std::make_shared<EpaisseurNode>())
            {}
    
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
        FormeGeometriqueAvecTaille(ExpressionPtr size):    
            _tailleNode(std::make_shared<TailleNode>(size)) {}

        FormeGeometriqueAvecTaille(ExpressionPtr w, ExpressionPtr h):    
            _tailleNode(std::make_shared<TailleNode>(w, h)) {}

        ExpressionPtr getHeight() const {
            return _tailleNode->height();
        }

        ExpressionPtr getWidth() const {
            return _tailleNode->width();
        }
}; 

class FG_TailleUniforme: public FormeGeometriqueAvecTaille {
    public:
        FG_TailleUniforme(ExpressionPtr size):
            FormeGeometriqueAvecTaille(size) {}

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
        FG_TailleNonUniforme(ExpressionPtr w, ExpressionPtr h):    
            FormeGeometriqueAvecTaille(w,h) {}

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
    private:
        std::shared_ptr<PositionNode> _positionNode;

    public:
        CarreNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr size):
            FG_TailleUniforme(size), 
            _positionNode(std::make_shared<PositionNode>(x, y))
        {}


    Position center(Contexte & contexte) const {
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
        std::shared_ptr<PositionNode> _p1, _p2, _p3, _p4;
        std::shared_ptr<TailleNode> _tailleNode;

    public:
        RectangleNode(ExpressionPtr x1,  ExpressionPtr y1,ExpressionPtr x2,  ExpressionPtr y2,ExpressionPtr x3,  ExpressionPtr y3,ExpressionPtr x4,  ExpressionPtr y4):
            FormeGeometrique(), 
            _p1(std::make_shared<PositionNode>(x1, y1)),
            _p2(std::make_shared<PositionNode>(x2, y2)),
            _p3(std::make_shared<PositionNode>(x3, y3)),
            _p4(std::make_shared<PositionNode>(x4, y4)),
            _tailleNode(nullptr)
            {}


    Position center(Contexte & contexte) const {
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p1->pos().x(), _tailleNode->width(),OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p1->pos().y(), _tailleNode->height(),OperateurBinaire::plus);
        
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p4->pos().x(), _p1->pos().x(),OperateurBinaire::moins);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p2->pos().y(), _p1->pos().y(),OperateurBinaire::moins);
        
        _tailleNode = std::make_shared<TailleNode>(cX,cY);

        return "<rect " +
            _p1->analyseCode(contexte) +
            _tailleNode->analyseCode(contexte) +
            FormeGeometrique::analyseCode(contexte) +
            "/>\n";
    }
};

class TriangleNode: public FG_TailleNonUniforme{
    private:
        std::shared_ptr<PositionNode> _positionNode;

    public:
        TriangleNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr w, ExpressionPtr h):
            FG_TailleNonUniforme(w,h), 
            _positionNode(std::make_shared<PositionNode>(x, y))
        {}


    Position center(Contexte & contexte) const {
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
    private:
        std::shared_ptr<PositionNode> _positionNode;

    public:
        CercleNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr r):
            FG_TailleUniforme(r), 
            _positionNode(std::make_shared<PositionNode>(x, y))
        {}


    Position center(Contexte & contexte) const {
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
        std::shared_ptr<PositionNode> _positionNode;
        std::shared_ptr<TailleNode> _tailleNode;

    public:
        EllipseNode(ExpressionPtr x,  ExpressionPtr y, ExpressionPtr w, ExpressionPtr h):
            FG_TailleNonUniforme(w, h), 
            _positionNode(std::make_shared<PositionNode>(x, y))
        {}


    Position center(Contexte & contexte) const {
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
        std::shared_ptr<PositionNode> _p1, _p2;

    public:
        LigneNode(ExpressionPtr x1,  ExpressionPtr y1,ExpressionPtr x2,  ExpressionPtr y2):
            FormeGeometrique(), 
            _p1(std::make_shared<PositionNode>(x1, y1)),
            _p2(std::make_shared<PositionNode>(x2, y2))
        {}


    Position center(Contexte & contexte) const {
        ExpressionPtr const_2 = std::make_shared<Constante>(2);

        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_p1->pos().x(), _p2->pos().x(), OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_p1->pos().y(), _p2->pos().y(), OperateurBinaire::plus);
        cX = std::make_shared<ExpressionBinaire>(cX,const_2,OperateurBinaire::divise);
        cY = std::make_shared<ExpressionBinaire>(cY,const_2,OperateurBinaire::divise);
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        double x1 = _p1->pos().x()->calculer(contexte);
        double y1 = _p1->pos().y()->calculer(contexte);
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
};
class CheminNode: public FormeGeometrique{
    private:
        std::vector<Position> _vectPos;

    public:
        CheminNode(std::vector<Position> v):
            FormeGeometrique(), 
            _vectPos(v)
        {}


    Position center(Contexte & contexte) const {
        ExpressionPtr const_2 = std::make_shared<Constante>(2);
        ExpressionPtr cX = std::make_shared<ExpressionBinaire>(_vectPos.front().x(), _vectPos.back().x(),OperateurBinaire::plus);
        ExpressionPtr cY = std::make_shared<ExpressionBinaire>(_vectPos.front().y(), _vectPos.back().y(),OperateurBinaire::plus);
        cX = std::make_shared<ExpressionBinaire>(cX,const_2,OperateurBinaire::divise);
        cY = std::make_shared<ExpressionBinaire>(cY,const_2,OperateurBinaire::divise);
        Position c = Position(cX, cY);
        return c;
    }

    std::string analyseCode(Contexte & contexte) override{
        std::string toutes_les_lignes = "";
        double cX1 = _vectPos.front().x()->calculer(contexte);
        double cY1 = _vectPos.front().y()->calculer(contexte);
        for(auto i : _vectPos) {
            double cX2 = i.x()->calculer(contexte);
            double cY2 = i.y()->calculer(contexte);
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


    Position center(Contexte & contexte) const {
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
};

class ModificationFigureNode: public Noeud {
    protected:
        std::shared_ptr<AccesFigureNode> _accesFigure;
        std::shared_ptr<FigureNode> _figure;

    public:
        ModificationFigureNode(std::shared_ptr<AccesFigureNode> accesFigure):
            Noeud(), _accesFigure(accesFigure), _figure(nullptr){}


        virtual void modificate(Contexte & contexte) = 0;

        std::string analyseCode(Contexte & contexte) override {
            return "";
        }

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



class DeclarationVariable: public Noeud {
    private: 
        std::string _nomVariable;
        std::shared_ptr<FigureNode> _valueNode;

    public:
        DeclarationVariable(std::string const & nomVariable, std::shared_ptr<FigureNode> valueNode):
            Noeud(),
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
            if(std::shared_ptr<CarreNode> c = std::dynamic_pointer_cast<CarreNode>(_valueNode)){
                return c->analyseCode(contexte);
            }

            return "";
        }
};

