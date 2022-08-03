#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <windows.h>
#include <wchar.h> 
#include <wincon.h>
#include <time.h>

void shuffle(char ** ar, int size);

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*void paintC()
{
    system("cls");
    /*
 ██████╗                   ██╗ ██████╗ ███╗   ██╗ ██████╗ 
██╔════╝                   ██║██╔═══██╗████╗  ██║██╔════╝ 
██║         █████╗         ██║██║   ██║██╔██╗ ██║██║  ███╗
██║         ╚════╝    ██   ██║██║   ██║██║╚██╗██║██║   ██║
╚██████╗              ╚█████╔╝╚██████╔╝██║ ╚████║╚██████╔╝
 ╚═════╝               ╚════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 

 */
/*
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

    
    printmultiplelines(ce,30,20,6,4);
    printmultiplelines(jong,38,20,6,1|2|4);


    /*
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    wprintf(L" ██████╗\n");
    wprintf(L"██╔════╝\n");
    wprintf(L"██║     \n");
    wprintf(L"██║     \n");
    wprintf(L"╚██████╗\n");
    wprintf(L" ╚═════╝\n");
    
    
    while(1)
    {

    }
*/
/*
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    gotoxy(8,0);
    wprintf(L"                   ██╗ ██████╗ ███╗   ██╗ ██████╗ ");
    gotoxy(8,1);
    wprintf(L"                   ██║██╔═══██╗████╗  ██║██╔════╝ ");
    gotoxy(8,2);
    wprintf(L"    █████╗         ██║██║   ██║██╔██╗ ██║██║  ███╗");
    gotoxy(8,3);
    wprintf(L"    ╚════╝    ██   ██║██║   ██║██║╚██╗██║██║   ██║");
    gotoxy(8,4);
    wprintf(L"              ╚█████╔╝╚██████╔╝██║ ╚████║╚██████╔╝");
    gotoxy(8,5);
    wprintf(L"               ╚════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ");

    */
/*
/*
int main()
{
    _setmode(_fileno(stdout), 0x00020000);
    
    return 0;
}

*/



void shuffle(char ** arr,int size)
{
    srand(time(0));
    if (size > 1)
    {
        int i;
        //step through each index of the city name array
        for (i = 0; i < size - 1; i++)
        {
        //pick a random index (j) to swap it with
        //okay to pick same value as i
        int j = rand() % size; //random between 0 and 10
        const char* temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        }
    }
}

int main()
{

    char *au[] = {"ab","cd","ef","gh","ij","kl","mn","op","qr","st"};

    shuffle(au,10);

    for (int i = 0 ; i < 10; i++)
    {
        printf("%s,",au[i]);
    }

    return 0;
}

