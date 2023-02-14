#ifndef FIGURE_HEADER_H
#define FIGURE_HEADER_H

#include <xc.h> 


/**
    <p><b>Function prototype: </b>char random_number(char max_number);</p>
  
    <p><b>Summary: </b>Giving random value</p>
    <p><b>Description: </b>Function returns random integer number between 0 and 'max_number'</p>
    <p><b>Precondition: </b>Parameter must be positive integer</p>
    <p><b>Parameters: </b>'max_number' - integer number 'char' type</p>
    <p><b>Returns: </b>Positive integer pseudorandom number</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks: </b>Function returns pseudorandom number</p>
 */
char random_number(char max_number, char x);



/**
    <p><b>Function prototype: </b>void choose_new_figure(char * fig_bin_array);</p>
  
    <p><b>Summary: </b>Choosing next figure</p>
    <p><b>Description: </b>Function choose next random figure and stores in pointer given as parameter</p>
    <p><b>Precondition: </b>Pointer needs to point to array with at least 4 elements</p>
    <p><b>Parameters: </b>'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns: </b>No return (void)</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
void choose_new_figure(char* fig_bin_array, char x);


/**
    <p><b>Function prototype: </b>void prepare_new_figure(char* matrix, char* fig_bin_array);</p>
  
    <p><b>Summary: </b>Preparing new figure to be displayed od LED matrix display</p>
    <p><b>Description:</b>Function receives two char pointers. First pointer points to main matrix that represents LED display, second pointer points to figure represented by array with 4 elements. Function takes given figure and place it into first four rows of the main matrix.</p>
    <p><b>Precondition:</b></p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'fig_bin_array' - char pointer to 4 element array.</p>
    <p><b>Returns:</b>No return (void)</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b>'matrix' is not real matrix, its actually array with each element represents row on LED matrix display </p>
 */
void prepare_new_figure(char* matrix, char* fig_bin_array, char x);


/**
    <p><b>Function prototype:</b>__bit can_go_further(char* matrix, char* matrix_row);</p>
  
    <p><b>Summary:</b>Function checks whether figure can go further on LED display</p>
    <p><b>Description:</b>Function receives two char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point. Using these parameters, function checks whether figure can go down on LED display.</p>
    <p><b>Precondition:</b></p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer</p>
    <p><b>Returns:</b>Value '1' if figure can continue moving down, value '0' if figure can't move anymore.</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
__bit can_go_further(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>void go_down_1place(char* matrix, char* matrix_row, char* fig_bin_array);</p>
  
    <p><b>Summary:</b>Function that moves figure one place down</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters, function move figure by one place down.</p>
    <p><b>Precondition:</b>Figure need to be able to move down in order to work properly</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>No return (void)</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b>Function does not check whether figure can or cannot move down.</p>
 */
void go_down_1place(char* matrix, char* matrix_row, char* fig_bin_array);
void go_left(char* matrix, char* matrix_row, char* fig_bin_array);
void go_right(char* matrix, char* matrix_row, char* fig_bin_array);
void rotate(char* matrix, char* matrx_row, char* fig_bin_array);
__bit can_go_left(char* matrix, char* matrix_row, char* fig_bin_array);
__bit can_go_right(char* matrix, char* matrix_row, char* fig_bin_array);
void remove_full_rows(char* matrix);
__bit move(char* temp, char* rotatedFigure, char* position);
void copy4 (char* array1, char* array2);
#endif	/* XC_HEADER_TEMPLATE_H */
