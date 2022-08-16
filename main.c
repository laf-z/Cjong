#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <wchar.h>

 /*┌───┐┌───┐┌───┐┌───┐┌───┐┌───┐┌───┐┌───┐┌───┐┌───┐
 │4  ││4  ││4  ││4  ││2  ││3  ││1  ││3  ││1  ││3  │
 │ ♣ ││ ☺ ││ ♣ ││ ♥ ││ ► ││ ♂ ││ ▼ ││ ▼ ││ ♠ ││ § │
 │  4││  4││  4││  4││  2││  3││  1││  3││  1││  3│
 └───┘*/

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void createboxjogo(char simbolo,int numero,int color,int x,int y)// PARAMETROS X E Y FALTANDO
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(color == 1)
    {
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    }
    else if(color == 2)
    {
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
    }
    else
    {
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    gotoxy(x,y);
    wprintf(L"┌───┐\n");
    gotoxy(x,y+1);
    wprintf(L"│%d  │\n",numero);
    gotoxy(x,y+2);
    wprintf(L"│ %c │\n",simbolo);
    gotoxy(x,y+3);
    wprintf(L"│  %d│\n",numero);
    gotoxy(x,y+4);
    wprintf(L"└───┘\n");
}
void createboxmenu(wchar_t *texto,int color) // PARAMETROS X E Y FALTANDO
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(color == 1)
    {
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    }
    else
    {
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    //gotoxy(x,y)
    wprintf(L"┌────────────────────┐\n");
    //gotoxy(x,y+1)
    wprintf(L"│%ls│\n",texto);
    //gotoxy(x,y+2)
    wprintf(L"└────────────────────┘");
}
void createboxteclas(char letra,int x,int y)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(letra != 'e')
    {
    gotoxy(x,y);
    wprintf(L"┌───┐");
    gotoxy(x,y+1);
    wprintf(L"│ %c │",letra);
    gotoxy(x,y+2);
    wprintf(L"└───┘");
    }
    else
    {
    gotoxy(x,y);
    wprintf(L"┌───┐");
    gotoxy(x,y+1);
    wprintf(L"│ ← │");
    gotoxy(x,y+2);
    wprintf(L"└─┐ │");
    gotoxy(x,y+3);
    wprintf(L"  │ │");
    gotoxy(x,y+4);
    wprintf(L"  └─┘");
    }

}
void printtab(int x_inicial,int y_inicial,int * tab)
{
    system("cls");
    int contador = x_inicial;
    int contador_y = y_inicial;
    for(int i = 0; i < 60; i++)
    {
        if(tab[i] == 1)
        {
        createboxjogo('c',3,0,contador,contador_y);
        }

    contador += 5;
    if(contador == x_inicial + 50)
    {
    contador_y += 5;
    contador = x_inicial;
        }
    }
}
void splash(int x,int y)
{
    createboxteclas('w',x+5,y);
    createboxteclas('s',x+5,y+3);
    createboxteclas('a',x,y+3);
    createboxteclas('d',x+10,y+3);
    createboxteclas('r',x+30,y+3);
    createboxteclas('f',x+50,y+3);
    createboxteclas('e',x+70,y+1);
    gotoxy(x+3,y+6);
    wprintf(L"movimento");
    gotoxy(x+28,y+6);
    wprintf(L"Randomiza");
    gotoxy(x+50,y+6);
    wprintf(L"Menu");
    gotoxy(x+68,y+6);
    wprintf(L"Seleciona");




}
void main()
{
    int tabss[60] = {0,0,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,0,1,1,1,0,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,0,1,1,1,0,1,1,1,
        1,1,1,1,1,1,1,1,1,1};
        
    _setmode(_fileno(stdout), 0x00020000);
    //createboxjogo('q',4,0);
    //wchar_t nome[] = L"        JOGAR       ";//TEM QUE TER 20 LETRAS INCLUINDO ESPAÇO
    //createboxmenu(nome,1);
    printtab(30,30,tabss);
    //printtab(55,5);
}
