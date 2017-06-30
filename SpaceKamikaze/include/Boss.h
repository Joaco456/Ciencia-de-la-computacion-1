#ifndef BOSS_H
#define BOSS_H
#include <Nave.h>


class Boss:public Nave
{
    private:
        int x,y;
        int barra;
        int vidas;
    public:
        Boss(int,int,int,int);
        void coordenada(int,int);
        void BajarVida(){barra--;}
        void crear();
        void mover();
        void BarraDeVida();
        //void VidaCorazones();
       // void Morir();
       // int X(){return x;}
        //int Y(){return y;}
        //int V(){return vidas;}
};

#endif // BOSS_H
