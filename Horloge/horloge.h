#ifndef HORLOGE_H
#define HORLOGE_H
#include "Clavier.h"
#include "cadran.h"
#include <time.h>
enum MODEHORLOGE
{
    AUCUN_REGLAGE,
    REGLAGE_MINUTES,
    REGLAGE_HEURES

};

class Horloge
{
public:
    Horloge(const int _nbMode=3,const int _resolution=24);
    ~Horloge();
    bool AvancerHeures();
    bool AvancerMinutes();
    void ReculerHeures();
    void ReculerMinutes();
    void ChangerMode();
    void ActualiserHeure();
    TOUCHES_CLAVIER Controler(TOUCHES_CLAVIER _numTouche=AUCUNE);
private:
    int heure=10;
    int minute=43;
    const int resolution;
    const int nbModes;
    int mode=0;
    time_t valAvant;
    Clavier *leClavier;
    Cadran *leCadran;
};

#endif // HORLOGE_H
