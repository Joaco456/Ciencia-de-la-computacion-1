#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"

using namespace std;

Nave::Nave(int _x,int _y)
{
    x = _x;
    y = _y;
}
void Nave::crear(){
    gotoxy(x,y); printf(     "%c",30);
    gotoxy(x,y+1); printf( "%c%c%c",91,236,93);
    gotoxy(x,y+2); printf("%c%c  %c%c",30,2,2,30);
}
void Nave::borrar(){
    gotoxy(x,y);printf("     ");
    gotoxy(x,y+1);printf("     ");
    gotoxy(x,y+2);printf("     ");
}
void Nave::mover(){
    if(kbhit()){
        char tecla = getch();
        borrar();
        if(tecla== IZQUIERDA)x--;
        if(tecla== DERECHA)x++;
        if(tecla== ARRIBA)y--;
        if(tecla==ABAJO)y++;
        crear();
    }
}









