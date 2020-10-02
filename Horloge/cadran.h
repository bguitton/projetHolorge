/**
  * @file   :   cadran.h
  * @author :   GUITTON baptiste
  * @date   :   1/10/2020
  * @detail :   Assure la gestion d'un cadran en mode texte
  *             à partir des séquences d’échappement ANSI
  */

#ifndef CADRAN_H
#define CADRAN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

using namespace std;
/**
 * @brief The Cadran class
 * @details définition de la classe cadran
 */
class Cadran
{
public:
    Cadran(const int _posX=1,const int _posY=1,const int _hauteur=1,const int _largeur=7,const int _couleurText=43,const int _couleurFond=35);
    ~Cadran();
    void Afficher(const string _texte, const int _position=0,const int _ligne=1);
    void Afficher(const int _valeur, const int _position=0,const int _ligne=1);
    void Effacer();
private:
    void PositionnerCurseur(const int _posx, const int _posy);
    /// coordonnée en X du premier caractère dans le cadran
    int ligne;
     /// coordonnée en Y du premier caractère dans le cadran
    int colonne;
     /// nombre de lignes du cadran
    int hauteur;
    /// nombre de caractères par ligne
    int largeur;
    ///couleur du fond
    int couleurFond;
    /// couleur Ecriture
    int couleurEcriture;

};

#endif // CADRAN_H
