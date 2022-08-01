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
            case 27:
                exit(0);
            default:
                wprintf(L"%c",k);
            
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
                printf("tutorial");
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

    wprintf(L"\n\n\n\n\n\n\n\n");
    wprintf(L"                                                ███╗   ███╗ █████╗ ██╗  ██╗     ██╗ ██████╗ ███╗   ██╗ ██████╗\n");
    wprintf(L"                                                ████╗ ████║██╔══██╗██║  ██║     ██║██╔═══██╗████╗  ██║██╔════╝\n");
    wprintf(L"                                                ██╔████╔██║███████║███████║     ██║██║   ██║██╔██╗ ██║██║  ███╗\n");
    wprintf(L"                                                ██║╚██╔╝██║██╔══██║██╔══██║██   ██║██║   ██║██║╚██╗██║██║   ██║\n");
    wprintf(L"                                                ██║ ╚═╝ ██║██║  ██║██║  ██║╚█████╔╝╚██████╔╝██║ ╚████║╚██████╔╝\n");
    wprintf(L"                                                ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝\n");
     
    wprintf(L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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

