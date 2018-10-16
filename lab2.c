/* Laboration 2 */

#include "lab2_funcs.h"
matlab_arr_t arrs[6] = { { 'A', {1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0,
                                 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0,
                                 5.0, 1.0, 2.0, 3.0, 4.0, 5.0, 1.0,
                                 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0,
                                 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0,
                                 1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0,
                                 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0,
                                 5.0}},
                         { 'B', {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0,
                                 7.0, 8.0, 9.0, 10.0, 11.0, 12.0,
                                 13.0, 14.0, 15.0, 16.0, 17.0, 18.0,
                                 19.0, 20.0, 21.0, 22.0, 23.0, 24.0,
                                 25.0, 26.0, 27.0, 28.0, 29.0, 30.0,
                                 31.0, 32.0, 33.0, 34.0, 35.0, 36.0,
                                 37.0, 38.0, 39.0, 40.0, 41.0, 42.0,
                                 43.0, 44.0, 45.0, 46.0, 47.0, 48.0,
                                 49.0}},
                          {'C'}, {'R'}, {'X'}, {'Y'}};

matlab_var_t vars[6] = { {'a'}, {'b'}, {'c'}, {'r'}, {'x'}, {'y'} };

double startValue, stopValue;


int main(int argc, char *argv[])
{
  char input[1000 + 1];

  while ( true ) {
    // read line from user
    readLine ( input );

    // writes out all valid commands to the user
    if ( (strcmp ( input, "help" )) == 0 ) {
      printHelp();
    }

    // exits the program
    else if ( ((strcmp ( input, "exit" )) == 0 ) ||
               (strcmp ( input, "quit" )) == 0 ) {
      exit(0);
    }

    // show array or variable
    else if ( (strncmp ( input, "show", 4 )) == 0 ) {
      show( input[5] );
    }

    // clears array or varible
    else if ( ( strncmp ( input, "clear", 5 )) == 0 ) {
	     clear( input[6]);
    }

    // sets array elements with even spaces from start to stop value
    else if ( (strncmp ( input, "array", 5 )) == 0 ) {
      segmentString( input );
      array( input [6], startValue, stopValue );
    }

    // sets a variable to a number and sets an array to a specific number in all elements
    else if( (strncmp ( input, "set", 3)) == 0 ){
	segmentString ( input );
	set ( input[4], startValue);
    }

    else {
      printf("Invalid expression. Try again or write 'help' to display valid commands.'\n");
      continue;
    }
  }

  return 0;
}
