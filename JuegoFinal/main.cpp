#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"




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
    Nave nave(7,7,3,3);
    nave.crear();
    nave.borrar();
    nave.ocultar();
    bool GameOver = false;
    while(!GameOver){

    nave.mover();
    nave.VidaCorazones();
    nave.Morir();
    Limites();
    Sleep(30);
    }

    return 0;
}
