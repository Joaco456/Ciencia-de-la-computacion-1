#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Nave.h"
#include "Boss.h"


Boss::Boss(int _x, int _y, int _barra):Nave(_vidas)
{
   x = _x;
   y = _y;
   barra = _barra;
}
void Boss::coordenada(int x,int y)
{
    HANDLE identi;
    identi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cursor;
    pos_cursor.X = x;
    pos_cursor.Y = y;

    SetConsoleCursorPosition(identi,pos_cursor);
}
void Boss::crear()
{
    coordenada(x,y);  printf("%c%c%c%c%c%c%c%c",31,40,2,206,206,2,41,31);
    coordenada(x,y+1);printf("    %c%c%c%c",92,92,47,47);
    coordenada(x,y+2);printf("    %c%c%c%c",237,60,62,237);
    coordenada(x,y+3);printf("       %c",216);
}
void Boss::mover()
{
    coordenada(x,y); printf("            ");
    y++;
    if(y>32){
        x = 50+2;
        y = 3;
    }
    crear();
}
void Nave::BarraDeVida(){
    coordenada(2,50); printf("Vida: %d",vida);
    coordenada(2,64); printf("Salud: ");
    coordenada(2,70); printf("       ");
    for(int i = 0; i<BarraDeVida; i++){
        coordenada(2,70+i);printf("%c",4);
    }
}
void Nave::Morir(){
    if(barra==0){
        borrar();
        coordenada(x,y);   printf("   ********  ");//EXPLOCIONES
        coordenada(x,y+1); printf("    ******   ");
        coordenada(x,y+2); printf("     ****    ");
        coordenada(x,y+3); printf("      **     ")
        Sleep(350);

        borrar();
        coordenada(x,y);   printf(" * ** * ");//EXPLOCIONES 2
        coordenada(x,y+1); printf("  ****  ");
        coordenada(x,y+2); printf(" * ** * ");
        coordenada(x,y+2); printf(" * ** * ");

        Sleep(350);

        borrar();
        vidas--;
        crear();
        barra = 10;
        BarraDeVida();

    }
}


Boss::~Boss()
{

}
