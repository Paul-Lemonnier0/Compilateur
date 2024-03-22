# COMPILATEUR

Implémentation d'un compilateur de création de formes en svg en utilisant flex, bison, c++.   

## Description

Dans ce répertoire, un compilateur de création de formes en svg est disponible.     

L'objectif est de pouvoir créer des formes en utilisant des boucles, des conditions, des fonctions.   
Chaque forme à des attributs.   

Il est possible d'accéder aux formes par variables ou par tableau : carré[0], ...   

Il est aussi possible de créer des variables booléennes, flottantes, entières.   

## Fichiers disponibles

Un scanner (scanner.ll) qui se charge de récupérer les mots-clés et les valeurs rentrées (token)  
Un parser (parser.yy) qui se charge d'interpréter la grammaire   
Un driver (driver.hh, driver.cpp) qui se charge de faire l'interface entre la structure de données et le parser   
Un contexte (contexte.hh, contexte.cpp) qui implémente un conteneur de variables   

Une structure de données en forme d'arbre (AST). Celle-ci est disponible en plusieurs fichiers dans le dossier "expression"   

## Utilisation

fonction ...

```
fonction dessiner () {
    Instructions 1 ( voir après) 
    (...)
    Instructions n  
}

```

Puis 2 retour à la ligne consécutif (lancera la fonction dessiner qui peut appeler des fonctions extérieurs)

Si l'instruction : " taille x y; " n'est pas défini dans dessiner alors rien ne s'affiche car le caneva n'est pas considéré comme défini

Pour une utilisation plus simple il est possible de passer outre la fonction dessiner, pour cela il faut, dans le fichier arbre.cc, décommenter la partie sans le point d'entré dessiner ( ligne 252-264) et mettre en commentaire la partie avec le point d'entré dessiner ( ligne 233-249 )

En faisant cela l'utilisation devient :

```
Instructions 1
(...)
Instructions n
```

Puis 2 retours à la ligne consécutif (l'utilisation des fonctions reste possible, simplement si on veut les éxécuter il faut les appeler)

## Utilisation détaillée

Déclaration du caneva

```
taille 1000 1000;
```

### Exemples d'utilisations

#1

```
taille 1000 1000;
carré 250 250 100;
rectangle 100 100 100 200 150 200 150 100;
triangle 400 100 50 80;
cercle 400 400 50;
ligne 10 10 490 490;
chemin 10 10, 490 10, 490 490, 10 490, 10 10;
texte 100 100 "Bonjour" "Liberation Serif";
```

#2

```
taille 1000 1000;
carré 250 250 100 -> couleur : rouge & opacité : 30%;
rectangle 100 100 100 200 150 200 150 100 {
rotation : 45°;
épaisseur : 5;
}
cercle 400 400 50 -> couleur : vert & remplissage : bleu & épaisseur : 3;
```

#3

```
taille 1000 1000;
C1 = carré 0 0 0 -> couleur : rouge & opacité : 30%;
C1.positionX = 250;
C1.positionY = 250;
C1.taille = 100;
carré[0].couleur = bleu;
carré[0].épaisseur = 10;
C1.remplissage = rouge;
C1.opacité = 50%;
rectangle 0 0 0 0 0 0 0 0;
rectangle[0].rotation = 45°;
rectangle[0].positionX1 = 100;
rectangle[0].positionY1 = 100;
rectangle[0].positionX2 = 100;
rectangle[0].positionY2 = 200;
rectangle[0].positionX3 = 150;
rectangle[0].positionY3 = 200;
rectangle[0].positionX4 = 150;
rectangle[0].positionY4 = 100;
```

#4

```
C1 = carré 250 250 100;
si (C1.positionX > 250) alors {
C1.couleur = rouge;
}
sinon {
C1.couleur = vert;
}
si (C1.positionY <= 250) alors {
C1.remplissage = bleu;
}

si ((C1.hauteur == 50) && (C1.largeur != 50)) alors {
C1.opacité = 0%;
}
sinon {
C1.opacité = 50%;
}
si (C1.couleur est rouge) alors {
C1.taille = 50;
}

si (C1.couleur n'est pas rouge) alors {
C1.taille = 200;
}

taille 1000 1000;
```

#5

```
entier i = 0;
tant que (i < 5) {
carré i*100 i*100 50;
i = i + 1;
}
entier j = 0;
répète 5 fois {
cercle j*100+25 j*100+25 25;
j = j + 1;
}
taille 1000 1000;
```

#6.1

```
fonction maison (x y taille) {
carré x y-taille taille;
triangle x y-taille taille taille;
}
fonction dessiner() {
maison 100 500 200;
}
taille 1000 1000;
dessiner;
```

#6.2 (avec le point d'entrée)

```
fonction maison (x y taille) {
carré x y-taille taille;
triangle x y-taille taille taille;
}
fonction dessiner() {
taille 1000 1000;
maison 100 500 200;
}
```

#7

```
carré 0 0 100 -> couleur : rouge;
carré 100 100 100 -> couleur : rgb(255,0,0);
carré 200 200 100 -> couleur : #ff0000;
taille 500 500;
```

#8

```
CaRrÉ 0 0 100 -> CouLeur : ROuge;
taille 300 300;
```

## Détails   

### Définition du caneva :
```
taille X Y
```

### Création de figures :  
```
carré x1 y1 taille   
rectangle x1 y1 x2 y2 x3 y3 x4 y4   
triangle x1 y1 longueur hauteur   
cercle x1 y1 rayon     
ellipse x1 y1 longueur hauteur   
ligne x1 y1 x2 y2   
chemin x1 y1, x2 y2, ..., xn yn   
texte x1 y1 "texte" "police d'écriture"    
```
    
### Gestion des attributs :   

- couleur :   
  * rgb(x,y,z)   
  *  #XXXXXX   
  *  rouge/vert/bleu/jaune/...   
  
- remplissage :    
  * idem que couleur    
   
- épaisseur :   
  * entier / opération / réel   

- opacité :    
  *  entier / opération / réel '%'   

- rotation :   
  *  entier / opération / réel '°'


### Attribution des attributs lors de la création d'une figure :
Inline :
```
déclarationFigure -> att1 : val1 & att2 : val2 & (...);
```

CSS : 
```
déclarationFigure {
    att1 : val1;   
    att2 : val2;  
    (...)   
} 
```

### Création de variables :
Figures   
Entier  
Réel   
Booléen       
Couleur   

### Accès figure :   
Index : carré[0], triangle[0], ...   
Variable   
   
### Accès position / taille d'une figure :

- carré :   
   * taille / hauteur / largeur   
   * positionX / positionY   
   
- rectangle :    
   * hauteur / largeur   
   * positionX1 / positionY1 / positionX2 / positionY2 / positionX3 / positionY3 / positionX4 / positionY4   

- triangle :  
   * hauteur / largeur   
   * positionX / positionY   

- cercle :   
   * taille / hauteur / largeur   
   * positionX / positionY   

- ellipse :   
   * hauteur / largeur    
   * positionX / positionY     
   
- ligne :    
   * positionX1 / positionY2   

- chemin :   
   * positionXY (Y un entier)   
 
     
### Assignation variable :  
```
i = i + 1;   
b = true;   
c = rouge;   
f = 0.5;   
```
### Modification figure :   
```
C1.couleur = rouge;    
carré[0].couleur = rouge (triangle[0].couleur = rouge, ...)   
```

### Structure conditionnelle (si / sinon) :   
Position d'une figure (<, >, ==, >=, <=, !=)   
Taille d'une figure (<, >, ==, >=, <=, !=)   
Couleur d'une figure (est / n'est pas)   

Comparaisons avec des constantes ou des variables   

Combinaisons de plusieurs conditions ((condition1) && (condition2))    

Pour déclarer un "si" sans "sinon" il faut sauter une ligne (por omettre le "sinon") exemple :   

```
si (condition) alors {   
    ...   
}
  
```

Avec le sinon : 

```
carré 20 20 20;   
si (condition) alors {   
    ...   
}   
sinon {   

}   
carré 20 20 20;   
```
### Boucles :
- Répète x fois :   
   * x une constante   
   * x une variable   

- Tant que condition :
   * Même condition que pour les structures conditionnelles    

### Fonctions :
- Création de fonctions :   
   * Avec arguments ou non    
   * Définitions des instructions    

-Appels de fonctions :

```
maison 100 100 100;    
dessin;
```   

- Dessiner en point d'entrée :
   * La fonction dessiner fonctionne comme un main, elle n'a pas besoin d'être appelée    
   * La taille du caneva ne peut être définie que dans la fonction dessiner (si on veut pouvoir la définir ailleurs on a simplement à regarder les noeuds internes de dessiner)    
   * Cette fonctionnaolité peut être décommentée pour que ça soit plus simple à tester (sans point d'entrée donc le code peut être écris sans fonction ou avec auquel cas il faut appeler dessiner et définir            la taille du caneva hors fonction)

### Insensible à la casse :

```
CaRrÉ 0 0 100 -> CouLeur : ROuge;   
```

### Conversion en svg :
Caneva    
Figures    
Attributs   

## Auteur

Paul Lemonnier     
paul.lemonnier49070@gmail.com  
