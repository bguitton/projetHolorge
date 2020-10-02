#include "horloge.h"



Horloge::Horloge(const int _nbMode, const int _resolution):
    resolution(_resolution),
    nbModes(_nbMode)


{
    leCadran= new Cadran(5,5);
    leClavier=new Clavier();
    valAvant=time(NULL);

}

Horloge::~Horloge()
{
    delete leCadran;
    delete leClavier;
}

bool Horloge::AvancerHeures()
{
    bool retour=false;
    heure++;
    if(resolution==12){
        if(heure==13){
            heure=1;
            retour=true;
        }
    }else{
        if(heure==24){
            heure=0;
            retour=true;
        }

    }
    return retour;
}

bool Horloge::AvancerMinutes()
{
    bool retour=false;
    minute++;
    if(minute==60){
        minute=0;
        retour=true;
    }
    return retour;
}

void Horloge::ReculerHeures()
{
    heure--;
    if(resolution==24){
    if(heure==-1){
        heure=24;
    }
    }else{
        if(heure==-1){
            heure=12;
    }
}
}
void Horloge::ReculerMinutes()
{
    minute--;
    if(minute==-1){
        minute=60;
    }
}
/**
 * @brief Horloge::ChangerMode
 * @details changer le mode de l'horloge
 */
void Horloge::ChangerMode()
{
    mode++;
    if(mode==nbModes){
        mode=0;
    }


}
/**
 * @brief Horloge::ActualiserHeure
 * @details permet d'augmenter les minutes
 */
void Horloge::ActualiserHeure()
{
    time_t valCourante=time(NULL);
    double seconde=difftime(valCourante,valAvant);
    if(seconde>1)// à modifier pour aller plus vitte
    {
        valAvant=valCourante;
        if(AvancerMinutes())
            AvancerHeures();
    }
}
/**
 * @brief Horloge::Controler
 * @param _numTouche
 * @return
 * @details Assure le fonctionnement de l'horloge pour le mode dans lequel elle se trouve.
 *          Elle reçoit lenuméro de la touche enfoncée, agit en accord avec le diagramme états-transitions de la classeHorloge.
 *          Assure les affichages correspondant au mode et retourne numéro de la toucheenfoncée après avoir scruté le clavier à la fin de la méthode
 */

TOUCHES_CLAVIER Horloge::Controler(TOUCHES_CLAVIER _numTouche)
{
    TOUCHES_CLAVIER touche =leClavier->ScruterClavier();
if(touche==MODE){
ChangerMode();
}

    switch (mode) {
    case REGLAGE_HEURES:
        if(touche==PLUS){
            AvancerHeures();

        }
        if(touche==MOINS){
              ReculerHeures();
        }
        leCadran->Afficher("HH",1);
        leCadran->Afficher(heure,4);

        break;
    case REGLAGE_MINUTES:
        if(touche==PLUS){
          AvancerMinutes();
        }
        if(touche==MOINS){
            ReculerMinutes();
        }
        leCadran->Afficher("MM",1);
        leCadran->Afficher(minute,4);

        break;
    case AUCUN_REGLAGE:
        ActualiserHeure();
        leCadran->Afficher(heure,1);
        leCadran->Afficher(minute,4);

        break;
    default:

        break;

}

   return touche;
}
