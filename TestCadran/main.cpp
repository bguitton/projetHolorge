/**
 * @brief main
 * @return
 * @author GUITTON Baptiste
 * @date 1/10/2020
 */
#include <iostream>
#include "cadran.h"
#include <unistd.h>

using namespace std;

int main()
{

    Cadran leCadran;
    Cadran unAutreCadran(5,1,2,20,31,46);
    /*Quelle est la position du cadran sur l’écran,
indiquer le nombre de ligne et lalargeur de l’afficheur (nombre de caractères affichables).
Il y a 3 ligne de 8 de largeurs sur les position y=2 et x=2
*/
    leCadran.Afficher(1,4,2);
    unAutreCadran.Afficher(2,15,2);
    unAutreCadran.Effacer();


    for(int i=10;i>=0;i--){
        unAutreCadran.Afficher(i,5,2);
        sleep(1);
        unAutreCadran.Effacer();
    }
    unAutreCadran.Afficher("Fin",5,1);
    char touche;
    cin>>touche;

    return 0;
}
