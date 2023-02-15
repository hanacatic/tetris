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
    <p><b>Function prototype: </b>void choose_new_figure(char * fig_bin_array)</p>
  
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
    <p><b>Function prototype: </b>void prepare_new_figure(char* matrix, char* fig_bin_array)</p>
  
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
    <p><b>Function prototype:</b>__bit can_go_further(char* matrix, char* matrix_row)</p>
  
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
    <p><b>Function prototype:</b>void go_down_1place(char* matrix, char* matrix_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that moves figure one place down</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function moves figure one place down.</p>
    <p><b>Precondition:</b>It must be possible to move the figure one place down.</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>No return (void)</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b>Function does not check whether figure can or cannot move down.</p>
 */
void go_down_1place(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>__bit can_go_left(char* matrix, char* matrix_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that tests whether figure can be moved left.</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function checks if the requested move - moving figure one place left - is possible.</p>
    <p><b>Precondition:</b>No preconditions</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>__bit - decision, answer to the question of can it be moved left</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
__bit can_go_left(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>void go_left(char* matrix, char* matrix_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that moves the figure on matrix one place left.</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function first calls function can_go_left and if its decision is true it moves the figure left.</p>
    <p><b>Precondition:</b>In order to move the figure left it must be possible to do so. Function will in any case check on its own if the move is possible.</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>void</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
void go_left(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>__bit can_go_right(char* matrix, char* matrix_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that tests whether figure can be moved right.</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function checks if the requested move - moving figure one place right - is possible.</p>
    <p><b>Precondition:</b>No preconditions</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>__bit - decision, answer to the question of can it be moved right</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
__bit can_go_right(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>void go_right(char* matrix, char* matrix_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that moves the figure on matrix one place right.</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function first calls function can_go_right and if its decision is true it moves the figure right.</p>
    <p><b>Precondition:</b>In order to move the figure left it must be possible to do so. Function will in any case check on its own if the move is possible.</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>void</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
void go_right(char* matrix, char* matrix_row, char* fig_bin_array);


/**
    <p><b>Function prototype:</b>__bit can_rotate(char* matrix, char* matrix_row, char* fig_bin_array, char* temp)</p>
  
    <p><b>Summary:</b>Function that determines if rotation of figure is possible.</p>
    <p><b>Description:</b>Function receives four char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point, third pointer points to figure binary representation and last pointer to binary representation of the figure. Using these parameters function determines if rotation is possible.</p>
    <p><b>Precondition:</b>In order to move the figure left it must be possible to do so. Function will in any case check on its own if the move is possible.</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>__bit - decision on can_rotate</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
__bit can_rotate(char* matrix, char* matrix_row, char* fig_bin_array, char* temp);


/**
    <p><b>Function prototype:</b>void rotate(char* matrix, char* matrx_row, char* fig_bin_array)</p>
  
    <p><b>Summary:</b>Function that rotates figure on matrix</p>
    <p><b>Description:</b>Function receives three char pointers. First pointer points to main matrix that represent LED display, second pointer points to variable that stores position on matrix of lowest figure point and the last pointer points to figure binary representation. Using these parameters function decides if rotation is possible - calls function can_rotate and if so rotates the figure.</p>
    <p><b>Precondition:</b>In order to rotate the figure left it must be possible to do so. Function will in any case check on its own if the move is possible.</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array, 'matrix_row' - char pointer, 'fig_bin_array' - char pointer to 4 element array</p>
    <p><b>Returns:</b>void</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
void rotate(char* matrix, char* matrx_row, char* fig_bin_array);
/**
    <p><b>Function prototype:</b>void remove_full_rows(char* matrix)</p>
  
    <p><b>Summary:</b>Funcion that cleares any full rows</p>
    <p><b>Description:</b>Function removes all full rows and drops the rows above for 1 row. In case there are multiple rows to delete, it will delete them all one by one from the last to the first and only after that can leds be updated.</p>
    <p><b>Precondition:</b>There has to be a row which is full - meaning it consists of '11111111'</p>
    <p><b>Parameters:</b>'matrix' - char pointer to 20 element array</p>
    <p><b>Returns:</b>void</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */

void remove_full_rows(char* matrix, char* time);


/**
    <p><b>Function prototype:</b>__bit move(char* temp, char* rotatedFigure, signed char* position)</p>
  
    <p><b>Summary:</b>Function that moves figure (needed because rotations are coded beforehand, but are placed on the center, this function moves those rotations of the figure left or right to where it is supposed to be, of course only if it is possible).
    <p><b>Description:</b>Function receives three char pointers. First pointer points to a temporary variable will store rotated figure - binary representation of the figure, second pointer points to a variable that stores predefined rotation of the figure - the binary representation, and the last pointer points to the number of times figure was moved left and right. Using these parameters function moves figure left or right as many times as left and right buttons were clicked since the figure showed up.</p>
    <p><b>Precondition:</b>In order to rotate the figure left it must be possible to do so. Function will in any case check on its own if rotation is possible.</p>
    <p><b>Parameters:</b>'temp' - char pointer to 4 element array, 'rotatedFigure' - char pointer to 4 element array, 'position' - char pointer</p>
    <p><b>Returns:</b>__bit - decision whether rotation is possible</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
__bit move(char* temp, char* rotatedFigure, signed char* position);


/**
    <p><b>Function prototype:</b>void copy4 (char* array1, char* array2)</p>
  
    <p><b>Summary:</b>Function that copies elements of array2 to array1</p>
    <p><b>Description:</b>Function receives two char pointers. First pointer points to char array to which elements will be copied and the second pointer points to char array whose elements will be copied. Using these parameters function copies elements from one array to another.</p>
    <p><b>Precondition:</b>Array1 needs to be able to store the elements of array2</p>
    <p><b>Parameters:</b>'array1' - char pointer array, 'array2' - char pointer array</p>
    <p><b>Returns:</b>void</p>
    <p><b>Example:</b></p>
    <code>
 
    </code>
    <p><b>Remarks:</b></p>
 */
void copy4 (char* array1, char* array2);
#endif	/* XC_HEADER_TEMPLATE_H */
