#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h> /* _beginthread , _endthread */
#include <conio.h> /* getch */
#include <windows.h> /* Sleep */
#include <wchar.h> /* wprintf */
#include <wincon.h>


char nameloopenabled = 1;
char menuenabled = 0;
int gx = 0;
int gy = 1;
/*
wchar_t * multiplystring(char sym, int val)
{
   char *temp = malloc(sizeof(char)*val);


   for(int i = 0; i < val; i++)
   {
        temp[i] = sym;
   }
   wchar_t  * str = malloc(strlen(temp)+1]);
   mbstowcs_s(NULL,str,strlen(temp)+1,temp,strlen(temp));
   
   return str;
}
*/
void gotoxy(int x, int y);
void getkey();
void enterhandler();
void namehandler(int counter);
char *getselectedarray(int num);
void nameloop();
void menu();
void tutorial();



int main()
{
    system("cls");
    _setmode(_fileno(stdout), 0x00020000);
    _beginthread(getkey,0,NULL);
    namehandler(1);
    while(1)
    {
        printf(".");
    }
    return 0;
}


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void getkey()
{    
    while(1)
    {
        char k = getch();
        /*wprintf(L"%d",k);*/

        switch(k)
        {
            case 32: // espaco
                if(menuenabled == 0)
                {
                    menuenabled = 1;
                    menu();
                }
                break;
            case 13: // enter
                enterhandler();
                break; 
            case 119: // cima
                if(gy > 1)
                {
                    gy--;
                }
                if(menuenabled == 1)
                {
                    menu();
                }
                break;
            case 97: // esquerda
                wprintf(L"<");    
                break;
            case 115: // baixo
                if(gy < 4)
                {
                    gy++;
                }
                if(menuenabled == 1)
                {
                    menu();
                }
                break;
            case 100: // direita
                wprintf(L">");
                break;
            case 102:
                menu();
                break;
            case 27:
                exit(0);
            default:
                wprintf(L"%d",k);
            
        }
        

    }
}
void enterhandler()
{
    if(menuenabled==1)
    {
        switch(gy)
        {
            case 1:
                printf("game");
                break;
            case 2:
                printf("dif");
                break;
            case 3:
                tutorial();
                break;
            case 4:
                exit(0);


        }
    }
}
void namehandler(int counter)
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    void printmultiplelines(wchar_t ** text,int x,int y,int lines,int color)
    {
        for(int i = 0; i < lines; i++)
        {
            gotoxy(x,y+i);
            SetConsoleTextAttribute(hConsole,color);
            wprintf(L"%ls",text[i]);
        }
    }

    wchar_t * ce[] = {L" ██████╗",L"██╔════╝",L"██║     ",L"██║     ",L"╚██████╗",L" ╚═════╝"};
    wchar_t * jong[] = {L"                   ██╗ ██████╗ ███╗   ██╗ ██████╗ ",L"                   ██║██╔═══██╗████╗  ██║██╔════╝ ",L"    █████╗         ██║██║   ██║██╔██╗ ██║██║  ███╗",L"    ╚════╝    ██   ██║██║   ██║██║╚██╗██║██║   ██║",L"              ╚█████╔╝╚██████╔╝██║ ╚████║╚██████╔╝",L"               ╚════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "};

    
    printmultiplelines(ce,53,15,6,4);
    printmultiplelines(jong,61,15,6,1|2|4);
    wprintf(L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    wprintf(L"                                                            PRESSIONE ESPAÇO PRA CONTINUAR..."/*+ gen_f.dots_handler(counter)*/);

}
void nameloop() // calls namehandler
{
    int counternameloop = 0;
    while(nameloopenabled == 1)
    {
        counternameloop++;
        Sleep(250);
        system("cls");
        namehandler(counternameloop);
    }
}
char *getselectedarray(int num)
{
    char *selectedarray = malloc(num);
    for(int i = 0; i < num; i++)
    {
        if(i + 1 == gy)
        {
            selectedarray[i] = 1;
        }
        else
        {
            selectedarray[i] = 0;
        }
    }
    return selectedarray;
}

void menu()
{
    system("cls");
    void createboxmenu(wchar_t *texto,int color,int x,int y) // PARAMETROS X E Y FALTANDO
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
        gotoxy(x,y);
        wprintf(L"┌────────────────────┐");
        gotoxy(x,y+1);
        wprintf(L"│%ls│",texto);
        gotoxy(x,y+2);
        wprintf(L"└────────────────────┘");
    }
    wchar_t botoesmenu[4][21] = {L"       JOGAR        ",L"     DIFICULDADE    ",L"     COMO JOGAR     ",L"        SAIR        "};

    char countermenu = 0;
    for(int i = 0; i < 4; i++)
    {
        createboxmenu(botoesmenu[i],getselectedarray(4)[countermenu],73,15+countermenu*3);
        countermenu++;
    }

}
void tutorial()
{
    system("cls");
    gotoxy(71,0);
    wprintf(L"Objetivo do Jogo:");
    gotoxy(41,3);
    wprintf(L"-Combinar todas as peças todas as peças do tabuleiro antes que o tempo acabe.");
    gotoxy(73,6);
    wprintf(L"Peças Abertas:");
    gotoxy(17,9);
    wprintf(L"-Diz-se que uma peça está aberta ou exposta se puder ser movida para a esquerda ou para a direita sem perturbar outras peças.");
    gotoxy(36,12);
    wprintf(L"-Duas peças abertas idênticas podem ser combinadas para liberar um espaço no tabuleiro.");
    gotoxy(74,15);
    wprintf(L"Como jogar:");
    gotoxy(34,18);
    wprintf(L"-O jogador deve combinar todas as peças abertas do tabuleiro antes que o tempo acabe.");
    gotoxy(57,21);
    wprintf(L"-Use as setas do teclado para mover o cursor.");
    gotoxy(51,24);
    wprintf(L"-Pressione Enter para selecionar duas peças e combiná-las.");
    gotoxy(45,27);
    wprintf(L"-Ficou preso? pressione R para randomizar as peças do tabuleiro atual.");
    gotoxy(61,30);
    wprintf(L"-Pressione F para voltar para o menu.");
    gotoxy(54,33);
    wprintf(L"-Pressione Esc a qualquer momento para sair do jogo.");
    gotoxy(68,38);
    wprintf(L"PRESSIONE F PARA VOLTAR");
    gotoxy(74,41);
    wprintf(L"BOM JOGO !!!");
}
