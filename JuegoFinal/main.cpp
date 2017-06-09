#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Asteroide.h"
#include "Bala.h"




using namespace std;

void coordenada(int x, int y){
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;
    SetConsoleCursorPosition(identi,pos_cursor);
}
void Ocultar_cursor(){
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 50;
    cursor.bVisible = false;
    SetConsoleCursorInfo(identi, &cursor);
}

void Limites(){
    for(int i = 2; i<78; i++){ //limites arriba y abajo
        coordenada(i,3); printf("%c",205);
        coordenada(i,33); printf("%c",205);
    }

    for(int i =4; i<33; i++){ //limites derecha y izquierda
        coordenada(2,i); printf("%c",186);
        coordenada(77,i); printf("%c",186);
    }
    //bordes
    coordenada(2,3); printf("%c",201);
    coordenada(2,33); printf("%c",200);
    coordenada(77,3); printf("%c",187);
    coordenada(77,33); printf("%c",188);

}

int main()
{
    Nave nave(35,30,3,3);

    //Asteroide ast(10,4), ast2(4,8), ast3(10,15), ast4(4,15);
    list<Asteroide *> asteroides;
    list<Asteroide *>::iterator it;
    for(int i = 0; i<4; i++){
        asteroides.push_back(new Asteroide(rand()%75+3, rand()%5+4));
    }

    list <Bala *> balas;
    list <Bala *>::iterator i;
    nave.crear();
    nave.borrar();
    nave.ocultar();
    bool GameOver = false;
    int puntos = 0;
    while(!GameOver){
        coordenada(4,2); printf("PUNTOS %d", puntos);

        //RUTINA DE DISPAROS
        if(kbhit())
        {
          char tecla = getch();
          if(tecla == 'n')
            balas.push_back(new Bala(nave.X()+2, nave.Y()-1));
        }
        //DISPAROS NO SE QUEDEN EN EL FONDO
        for(i = balas.begin(); i != balas.end(); i++)
        {
            (*i)->mover();
            if((*i)->fuera()){
                coordenada((*i)->X(), (*i)->Y()); printf(" ");
                delete (*i);
                i = balas.erase (i);
            }

        }
        for(it = asteroides.begin(); it != asteroides.end(); it++)
        {
            (*it)->mover();
            (*it)->choque(nave);
        }
        //COLISION BALAS/ASTEROIDES
        for(it = asteroides.begin(); it != asteroides.end(); it++){
            for(i = balas.begin(); i != balas.end(); i++){
                if((*it)->X() == (*it)->X() &&  ( (*it)->Y()+1 == (*it)->Y() || (*it)->Y() == (*it)->Y())){
                    coordenada((*i)->X(), (*i)->Y()); printf("     ");
                    delete (*i);
                    i = balas.erase(i);

                    asteroides.push_back(new Asteroide(rand()%74+3, 4));
                    coordenada((*it)->X(), (*it)->Y()); printf("    ");
                    delete(*it);
                    it = asteroides.erase(it);
                    puntos+=5;

                }
            }
        }

    nave.mover();

    nave.VidaCorazones();
    nave.Morir();
    Limites();
    if(nave.V()==0) GameOver = true;
    Sleep(40);
    }

    return 0;
}
