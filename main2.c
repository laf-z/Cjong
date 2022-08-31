#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h> /* _beginthread , _endthread */
#include <conio.h> /* getch */
#include <windows.h> /* Sleep */
#include <wchar.h> /* wprintf */
#include <wincon.h>
#include <io.h>


char splashenabled = 1, nameloopenabled = 0 , menuenabled = 0, difficultyenabled = 0, gameenabled = 0, haspressed = 0;
int gx = 0, gy = 1, gz = 1, sx = NULL, sz = NULL, diff = 4, csizex, csizey;
int ttab[60] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
/* general functions */void gotoxy(int x, int y); int * wheretogo(int sizex, int sizey); void getkey(); void enterhandler(); char *getselectedarray(int num); void createboxteclas(char letra,int x,int y); void createboxmenu(); void findcol(int x, int y, int z); void createboxjogo(char simbolo,int numero,int color,int x,int y); void printtab(int x_inicial,int y_inicial,int * tab);
/* game specific functions */void splash(); void menu(); void namehandler(int counter); void nameloop();void difficulty(); void tutorial(); void game();

int main()
{
    /* begin processes */ system("cls"); CONSOLE_SCREEN_BUFFER_INFO csbi; GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); csizex = (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2; csizey = (csbi.srWindow.Bottom - csbi.srWindow.Top + 1)/2; _setmode(_fileno(stdout), 0x00020000); _beginthread(getkey,0,NULL);
    /* start game */     int splashx = wheretogo(77,8)[0], splashy = wheretogo(77,8)[1];
    /*            */     splash(splashx,splashy);
    /* making sure program does not close */ while(1) printf(".");
    
    return 0;
}

void gotoxy(int x, int y)
{
  COORD coord;coord.X = x;coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int * wheretogo(int sizex, int sizey)
{
    int * ret = malloc(sizeof(int)*2); ret[0] = (int)csizex - sizex/2; ret[1] = (int)csizey - sizey/2;
    return ret;
}
void getkey()
{    
    while(1)
    {
        /*wprintf(L"%d",k);*/
        switch(getch())
        {
            case 32: // espaco
                if(menuenabled == 0 && nameloopenabled == 1){menuenabled = 1; menu();}
                break;
            case 13: // enter
                enterhandler();
                break; 
            case 119: // cima
                if(menuenabled == 1 && gy > 1){gy--; menu();}
                if(difficultyenabled == 1 && gy > 1){gy--; difficulty();}
                break;
            case 97: // esquerda
                wprintf(L"<");    
                break;
            case 115: // baixo
                if(menuenabled == 1 && gy < 4){gy++; menu();}
                if(difficultyenabled == 1 && gy < 4){gy++; difficulty();}
                break;
            case 100: // direita
                wprintf(L">");
                break;
            case 102:
                menu();
                break;
            case 27:
                exit(0);
            /*default:
                wprintf(L"%d",k);*/
        }
        haspressed = 1;
        if(haspressed == 1 && nameloopenabled == 0 && menuenabled == 0) {splashenabled = 0; nameloopenabled = 1; namehandler(1);};

    }
}
void enterhandler()
{
    if(menuenabled==1)
    {
        switch(gy)
        {
            case 1:
                game(); break;
            case 2:
                difficulty(); break;
            case 3:
                tutorial(); break;
            case 4:
                exit(0);
        }
    }
    else if(difficultyenabled == 1)
    {
        switch(gy)
        {
            case 1:
                diff = 4; menu(); break;
            case 2:
                diff = 3; menu(); break;
            case 3:
                diff = 2; menu(); break;
            case 4:
                diff = 0; menu(); break;
        }
    }
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
void createboxmenu(wchar_t *texto,int color,int x,int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(color == 1) /* red - cursor */ SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    else /* white - normal */ SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    gotoxy(x,y);   wprintf(L"┌────────────────────┐");
    gotoxy(x,y+1); wprintf(L"│%ls│",texto);
    gotoxy(x,y+2); wprintf(L"└────────────────────┘");
}
int findcol(int x, int y, int z)
{
   if(gz == z || sz == z)
   {
    if(10*(y-1)+x == sx && sz == z) return 2;
    else if(10*(y-1)+x == gx && gz == z) return 1;
    return 0;
   }
   
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
    gotoxy(x,y);    wprintf(L"┌───┐\n");
    gotoxy(x,y+1);  wprintf(L"│%d  │\n",numero);
    gotoxy(x,y+2);  wprintf(L"│ %c │\n",simbolo);
    gotoxy(x,y+3);  wprintf(L"│  %d│\n",numero);
    gotoxy(x,y+4);  wprintf(L"└───┘\n");
}
void printtab(int x_inicial,int y_inicial,int * tab)
{
    int contador = x_inicial;
    int contador_y = y_inicial;
    for(int i = 0; i < 60; i++)
    {
        if(tab[i] == 1)
        {
            createboxjogo('c',3,findcol(),contador,contador_y);
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    void createboxteclas(char letra,int x,int y)
    {

        if(letra != 'e')
        {
        gotoxy(x,y);   wprintf(L"┌───┐");
        gotoxy(x,y+1); wprintf(L"│ %c │",letra);
        gotoxy(x,y+2); wprintf(L"└───┘");
        }
        else
        {
        gotoxy(x,y);   wprintf(L"┌───┐");
        gotoxy(x,y+1); wprintf(L"│ ← │");
        gotoxy(x,y+2); wprintf(L"└─┐ │");
        gotoxy(x,y+3); wprintf(L"  │ │");
        gotoxy(x,y+4); wprintf(L"  └─┘");
        }

    }
    system("cls");
    createboxteclas('w',x+5,y);
    createboxteclas('s',x+5,y+3);
    createboxteclas('a',x,y+3);
    createboxteclas('d',x+10,y+3);
    createboxteclas('r',x+30,y+3);
    createboxteclas('f',x+50,y+3);
    createboxteclas('e',x+70,y+1);
    gotoxy(x+3,y+6);  wprintf(L"Movimento");
    gotoxy(x+28,y+6); wprintf(L"Randomiza");
    gotoxy(x+50,y+6); wprintf(L"Menu");
    gotoxy(x+68,y+6); wprintf(L"Seleciona");
    gotoxy(x+20,y+9); wprintf(L"PRESSIONE QUALQUER TECLA PARA CONTINUAR...");
}
void namehandler(int counter)
{

    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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

    
    printmultiplelines(jong,wheretogo(38,6)[0],wheretogo(38,6)[1],6,1|2|4); printmultiplelines(ce,wheretogo(58,6)[0],wheretogo(58,6)[1],6,4);
    gotoxy(wheretogo(33,-20)[0],wheretogo(33,-20)[1]);
    wprintf(L"PRESSIONE ESPAÇO PRA CONTINUAR..."/*+ gen_f.dots_handler(counter)*/);

}
void menu()
{
    system("cls");

    wchar_t botoesmenu[4][21] = {L"       JOGAR        ",L"     DIFICULDADE    ",L"     COMO JOGAR     ",L"        SAIR        "};

    char countermenu = 0;
    for(int i = 0; i < 4; i++)
    {
        createboxmenu(botoesmenu[i],getselectedarray(4)[countermenu],wheretogo(22,10)[0],wheretogo(22,10)[1]+countermenu*3);
        countermenu++;
    }

}
void difficulty()
{
    difficultyenabled = 1;
    menuenabled = 0;

    system("cls");

    wchar_t botoesdifficulty[4][21] = {L"      INICIANTE     ",L"     EXPERIENTE     ",L"        GÊNIO       ",L"      EINSTEIN      "};

    char counterdifficulty = 0;
    for(int i = 0; i < 4; i++)
    {
        createboxmenu(botoesdifficulty[i],getselectedarray(4)[counterdifficulty],wheretogo(22,10)[0],wheretogo(22,10)[1]+counterdifficulty*3);
        counterdifficulty++;
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
void game()
{
    /*gen symbols*/
    /*printtab*/
    gameenabled = 1;
    menuenabled = 0;
    
    system("cls");
    

    int tabx = wheretogo(50,30)[0], taby = wheretogo(50,30)[1];
    printtab(tabx,taby,ttab);
}






