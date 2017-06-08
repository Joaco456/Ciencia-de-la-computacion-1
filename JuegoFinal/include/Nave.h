#ifndef NAVE_H
#define NAVE_H


class Nave
{
    private:
        int x,y;
        int corazones;
        int vidas;

    public:
        Nave(int ,int, int, int);
        void coordenada(int,int);
        void ocultar();
        void crear();
        void borrar();
        void mover();
        void VidaCorazones();
        void Morir();
};

#endif // NAVE_H
