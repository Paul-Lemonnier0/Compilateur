#include "figure.hh"

std::string Figure::tostring() const {
    std::string str;
    std::string value = "aucune";
    if(_couleur != ""){
        value = _couleur;
    }

    str += "\n[" + getTypeFigure() + "]\n";

    str += "couleur : " + value + "\n";
    str += "rotation : " + std::to_string(_rotation) + "\n";

    if(_remplissage != ""){
        value = _remplissage;
    }

    else value = "aucune";

    str += "remplissage : " + value + "\n";
    str += "opacity : " + std::to_string(_opacity) + "\n";
    str += "epaisseur : " + std::to_string(_epaisseur) + "\n";

    return str;
}

std::string Rectangle::tostring() const {
    std::string str = Figure::tostring();
    str += "position1 : " + _p1.tostring() + "\n";
    str += "position2 : " + _p2.tostring() + "\n";
    str += "position3 : " + _p3.tostring() + "\n";
    str += "position4 : " + _p4.tostring() + "\n";

    return str;
}

std::string Carre::tostring() const {
    std::string str = Figure::tostring();
    str += "position : " + _p1.tostring() + "\n";
    str += "taille : " + std::to_string(_taille) + "\n";

    return str;
}

std::string Triangle::tostring() const {
    std::string str = Figure::tostring();
    str += "position : " + _p1.tostring() + "\n";
    str += "longueur : " + std::to_string(_longueur) + "\n";
    str += "hauteur : " + std::to_string(_hauteur) + "\n";

    return str;
}

std::string Cercle::tostring() const {
    std::string str = Figure::tostring();
    str += "position : " + _p1.tostring() + "\n";
    str += "rayon : " + std::to_string(_rayon) + "\n";

    return str;
}

std::string Ellipse::tostring() const {
    std::string str = Figure::tostring();
    str += "position : " + _p1.tostring() + "\n";
    str += "Longueur : " + std::to_string(_longueur) + "\n";
    str += "Hauteur : " + std::to_string(_hauteur) + "\n";

    return str;
}

std::string Ligne::tostring() const {
    std::string str = Figure::tostring();
    str += "position1 : " + _p1.tostring() + "\n";
    str += "position2 : " + _p1.tostring() + "\n";

    return str;
}

std::string Chemin::tostring() const {
    std::string str = Figure::tostring();
    int indice = 1;
    for(auto i : _vect) {
        str += "position" + std::to_string(indice) + " " + i.tostring() + "\n";
        indice ++;
    }

    return str;
}

std::string Texte::tostring() const {
    std::string str = Figure::tostring();
    str += "position : " + _p1.tostring() + "\n";
    str += "Texte : " + _texte + "\n";
    str += "Police :" + _police + "\n";

    return str;
}
