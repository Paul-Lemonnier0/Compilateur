#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>

#include "expression.hh"

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

class Position {
    private:
        ExpressionPtr _x, _y;

    public:
        Position(ExpressionPtr x, ExpressionPtr y): 
            _x(x), _y(y) {};

        Position(Position const & p) = default;

        double x() const {
            return _x->calculer();
        }

        double y() const {
            return _y->calculer();
        }

        /*

        std::string tostring() const {
            return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
        }

        */

        std::string toSVG() const {
            double x = _x->calculer();
            double y = _y->calculer();

            return "x=\"" + std::to_string(x) + "\" y=\"" + std::to_string(y) + "\"";
        }
};

class Figure {
    private:
        std::string _couleur;
        int _rotation;
        std::string _remplissage;
        float _opacity;
        float _epaisseur;

    public:
        Figure(std::string const & couleur, int rotation, std::string remplissage, 
            float opacity, float epaisseur):
                _couleur(couleur), _rotation(rotation), _remplissage(remplissage),
                _opacity(opacity), _epaisseur(epaisseur) {};


    //GETTERS
    std::string couleur() const { return _couleur; };
    std::string remplissage() const { return _remplissage; };
    int rotation() const { return _rotation; };
    float opacity() const { return _opacity; };
    float epaisseur() const { return _epaisseur; };

    void setCouleur(std::string coul) {
        _couleur = coul;
    }

    void setRemplissage(std::string remp) {
        _remplissage = remp;
    }

    void setRotation(int rot) {
        _rotation = rot;
    }

    void setOpacity(float opa) {
        _opacity = opa;
    }

    void setEpaisseur(float epai) {
        _epaisseur = epai;
    }

    virtual std::string getTypeFigure() const = 0;
    virtual std::string tostring() const;

    virtual std::string toSVG() const {

        return 
        "stroke-width=\"" + std::to_string(_epaisseur) + "\" " + 
        "opacity=\"" + std::to_string(_opacity) + "\" " + 
        "stroke=\"" + _couleur + "\" " + 
        "fill=\"" + _remplissage + "\"";
    }

    virtual FigureTypes getFigureType() const = 0;
};
class Rectangle: public Figure{
    private:
        Position _p1, _p2, _p3, _p4;

    public:
        Rectangle(std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
            int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4):
                Figure(couleur, rotation, remplissage, opacity, epaisseur),
                _p1(x1, y1),
                _p2(x2, y2),
                _p3(x3, y3),
                _p4(x4, y4) {};

        std::string getTypeFigure() const override { return "rectangle"; };
        std::string tostring() const;

        std::string toSVG() const override {
            std::string svg = "<rect " + _p1.toSVG();

            //svg += "width=\"" + std::to_string(_taille) + "\" width=\"" + std::to_string(_taille) + "\" ";
            svg += Figure::toSVG();
            svg += "/>";

            return svg;
        }

        FigureTypes getFigureType() const override { return FigureTypes::rectangle; }
};

class Carre: public Figure{
    private:
        Position _p1;
        int _taille;

    public:
        Carre(std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
            int x1, int y1, int taille):
                Figure(couleur, rotation, remplissage, opacity, epaisseur),
                _p1(x1, y1),
                _taille(taille) {};

        std::string getTypeFigure() const override { return "carre"; };
        std::string tostring() const;

        std::string toSVG() const override {
            std::string svg = "<rect " + _p1.toSVG();

            svg += " width=\"" + std::to_string(_taille) + "\" height=\"" + std::to_string(_taille) + "\" ";
            svg += Figure::toSVG();
            svg += "/>";

            return svg;
        }

        FigureTypes getFigureType() const override { return FigureTypes::carre; }
};


class Triangle: public Figure{
    private:
        Position _p1;
        int _longueur, _hauteur;

    public:
        Triangle(std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
            int x1, int y1, int longueur, int hauteur):
                Figure(couleur, rotation, remplissage, opacity, epaisseur),
                _p1(x1, y1),
                _longueur(longueur),
                _hauteur(hauteur) {};

        std::string getTypeFigure() const override { return "triangle"; };
        std::string tostring() const;

        std::string toSVG() const override {
            std::string svg = "<polygon ";

            svg += "points =\"" + std::to_string(_p1.x()) + "," + std::to_string(_p1.y()) + " ";
            svg += std::to_string(_p1.x() + _longueur) + "," + std::to_string(_p1.y()) + " ";
            svg += std::to_string(_p1.x() + _longueur / 2) + "," + std::to_string(_p1.y() - _hauteur) + "\"";

            svg += Figure::toSVG();
            svg += "/>";

            return svg;
        }

        FigureTypes getFigureType() const override { return FigureTypes::triangle; }
};

class Cercle: public Figure{
    private:
        Position _p1;
        int _rayon;

    public:
        Cercle(std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
            int x1, int y1, int rayon):
                Figure(couleur, rotation, remplissage, opacity, epaisseur),
                _p1(x1, y1),
                _rayon(rayon) {};

        std::string getTypeFigure() const override { return "cercle"; };
        std::string tostring() const;

        std::string toSVG() const override {
            std::string svg = "<circle ";
            
            svg += "cx=\"" + std::to_string(_p1.x()) + "\" cy=\"" + std::to_string(_p1.y()) + "\" ";
            svg += "r=\"" + std::to_string(_rayon);
            svg += Figure::toSVG();

            svg += "/>";

            return svg;
        }

        FigureTypes getFigureType() const override { return FigureTypes::cercle; }
};

class Ellipse : public Figure {
private : 
    Position _p1;
    int _longueur, _hauteur;
public :
    Ellipse (std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
             Position const & P, int longue, int haut) :
        Figure(couleur, rotation, remplissage, opacity, epaisseur),
        _p1(P),
        _longueur(longue),
        _hauteur(haut) {};
    std::string getTypeFigure() const override { return "ellipse"; };
    std::string tostring() const override;

    std::string toSVG() const override {
        return "";
    }

    FigureTypes getFigureType() const override { return FigureTypes::ellipse; }
};

class Ligne : public Figure {
private : 
    Position _p1, _p2;
public :
    Ligne (std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
           Position const & P1, Position const & P2) :
        Figure(couleur, rotation, remplissage, opacity, epaisseur),
        _p1(P1),
        _p2(P2) {};
    std::string getTypeFigure() const override { return "ligne"; };
    std::string tostring() const override;

    std::string toSVG() const override {
        std::string svg = "<circle ";
        
        svg += "x1=\"" + std::to_string(_p1.x()) + "\" y1=\"" + std::to_string(_p1.y()) + "\" ";
        svg += "x2=\"" + std::to_string(_p2.x()) + "\" y2=\"" + std::to_string(_p2.y()) + "\" ";

        svg += Figure::toSVG();
        
        svg += "/>";

        return svg;
    }

    FigureTypes getFigureType() const override { return FigureTypes::ligne; }
};

class Chemin : public Figure {
private : 
    std::vector<Position> _vect;
public :
    Chemin (std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
            std::vector<Position> const & V) :
        Figure(couleur, rotation, remplissage, opacity, epaisseur),
        _vect(V) {};
    std::string getTypeFigure() const override { return "chemin"; };
    std::string tostring() const override ;

    std::string toSVG() const override {
        return "";
    }

    FigureTypes getFigureType() const override { return FigureTypes::chemin; }
};

class Texte : public Figure {
private : 
    Position _p1;
    std::string _texte, _police;
public :
    Texte (std::string const & couleur, int rotation, std::string remplissage, float opacity, float epaisseur,
           Position const & P, std::string t, std::string p) :
        Figure(couleur, rotation, remplissage, opacity, epaisseur),
        _p1(P),
        _texte(t),
        _police(p) {};
    std::string getTypeFigure() const override { return "texte"; };
    std::string tostring() const override ;

    std::string toSVG() const override {
        return "";
    }

    FigureTypes getFigureType() const override { return FigureTypes::texte; }
};

























class Caneva {
    private:
        std::vector<std::shared_ptr<Figure>> _figures;
        int _longueur, _hauteur;

    public:
        Caneva(int longueur, int hauteur):
            _longueur(longueur), _hauteur(hauteur){};

        void ajouterFigure(std::shared_ptr<Figure> f) {
            _figures.push_back(f);
        }

        void afficherFigures() const {
            std::cout<<"\nFigures dans le caneva : \n";
            
            for(auto const & i: _figures){
                std::cout<<i->tostring()<<"\n";
            }

            std::cout<<"Fin de figures dans le caneva \n";
        }

        std::string tostring() const {
            std::string str = "caneva [";
            str += std::to_string(_longueur);
            str += ",";
            str += std::to_string(_hauteur);
            str += "]\n";

            return str;
        }

        void generateSVG() const {
            std::ofstream outFile("output.svg");

            outFile << "<svg version=\"1.1\" width=\"";
            outFile << std::to_string(_longueur);
            outFile << "\" height=\"";
            outFile << std::to_string(_hauteur);
            outFile << "\" xmlns=\"http://www.w3.org/2000/svg\">\n";


            for(auto const & f: _figures){
                outFile <<f->toSVG()<<"\n";
            }

            outFile << "</svg>";                        

            outFile.close();
        }
};
