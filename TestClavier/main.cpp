#include <iostream>
#include "Clavier.h"
using namespace std;

int main()
{
      Clavier unClavier;
      TOUCHES_CLAVIER touche;
    do {

       touche= unClavier.ScruterClavier();
       if(touche!=AUCUNE){
           cout<<touche<<endl;
       }
    } while (unClavier.ScruterClavier()!=FIN);



    return 0;
}
