#include "genf.h"
#include "specf.h"
#include "callf.h"

#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

void main() {
    int x = 0;
    int y = 1;
    int z = 1;
    int selected_x = NULL;
    int selected_z = NULL;
    int score = 0;
    int won = 0;

    int tab[3][60] = {
        {1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1}  ,
        
        {0,0,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,0,0}  ,

        {0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,1,1,1,1,0,0,
        0,0,1,1,1,1,1,1,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0}
    };

    int borda_E[3][6] = {
        {0,10,20,30,40,50},
        {10,20,30,40},
        {22,32}
        };
    
    int borda_D[3][6] = {
        {9,19,29,39,49,59},
        {19,29,39,49},
        {27,37}
        };

    int difficulty = 4;
    int name_loop_enabled = 0;
    int menu_enabled = 0;
    int difficulty_enabled = 0;
    int tutorial_enabled = 0;
    int game_enabled = 0;
    int game_started = 0;
    int countdown_enabled = 0;
    int has_pressed = 0;
    int botoes_menu[4] = {
        "       JOGAR        ",
        "     DIFICULDADE    ",
        "     COMO JOGAR     ",
        "        SAIR        "};
    int botoes_dificuldade[4]= {
        "      INICIANTE     ",
        "     EXPERIENTE     ",
        "        GÊNIO       ",
        "      EINSTEIN      "};
    int sym_lib[24] = {
        '♥','♦','♣','§','☺','♠',
        '•','♂','♀','♪','♫','►',
        '◄','▲','▼','ø','¶','!',
        '@','#','$','%','&','*'};
    int num_arr[] = {};
    int pressed_esc = 0;
    int borda_compare_array = NULL;
    int countdown_counter = 0;
    
    int getOffsetValue (int lineNum) {
        int v = 90 * lineNum;
        return round(sin( v * M_PI /180));
    };
    
    char dots_handler(int currentC) {
        return currentC % 4
    }
