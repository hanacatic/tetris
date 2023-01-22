#include "figure.h"
#include <stdio.h>  
#include <stdlib.h>


const char figures[7][4] = 
{ 
    {0b00000000, 0b00001000, 0b00001000, 0b00011000}, //J
    {0b00000000, 0b00010000, 0b00010000, 0b00011000}, //L
    {0b00010000, 0b00010000, 0b00010000, 0b00010000}, //I
    {0b00000000, 0b00000000, 0b00011000, 0b00011000}, //cube
    {0b00000000, 0b00010000, 0b00011000, 0b00001000}, //4
    {0b00000000, 0b00001000, 0b00011000, 0b00010000}, //z
    {0b00000000, 0b00000000, 0b00010000, 0b00111000}, //inverted T
};

char a = 4;

char random_number(char max_number){
        srand((a)); 
        a+=5;
        a *= rand();
        return (a)%max_number;     
}

void choose_new_figure(char* fig_bin_array){
    const char *pom = figures[random_number(7)];
    for(char i=0; i<4; i++){
        fig_bin_array[i] = pom[i];
    }
}

void prepare_new_figure(char* matrix, char* fig_bin_array){
    choose_new_figure(fig_bin_array);
    for(char i=0; i<4; i++)
        matrix[i] = fig_bin_array[i];
}


__bit can_go_further(char* matrix, char* matrix_row){
    while(!matrix[(*matrix_row)]) (*matrix_row)--;
    return((*matrix_row) < 19 && !(matrix[(*matrix_row)] & matrix[(*matrix_row)+1]));
}


void go_down_1place(char* matrix, char* matrix_row, char* fig_bin_array){
    for(char i=0; i<4; i++){
        matrix[(*matrix_row)+1-i] = matrix[(*matrix_row)+1-i] | (fig_bin_array[3-i]);
        matrix[(*matrix_row)-i] = matrix[(*matrix_row)-i] ^ (fig_bin_array[3-i]);
        
    }
    (*matrix_row)++;
}
