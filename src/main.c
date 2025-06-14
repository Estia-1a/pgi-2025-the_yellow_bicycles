#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode: 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */

if ( strncmp( configuration.command, "dimension", 10 ) == 0 ) {
    dimension( configuration.filenames[0] );
}
else if ( strncmp( configuration.command, "first_pixel", 12 ) == 0 ) {
    first_pixel(configuration.filenames[0] );
}

else if ( strncmp( configuration.command, "tenth_pixel", 12 ) == 0 ) {
    tenth_pixel( configuration.filenames[0] );
}

else if ( strncmp( configuration.command, "second_line", 12 ) == 0 ) {
    second_line(configuration.filenames[0] );
}

else if ( strncmp( configuration.command, "max_pixel", 10 ) == 0 ) {
    max_pixel(configuration.filenames[0] );
}
else if ( strncmp( configuration.command, "min_pixel", 10 ) == 0 ) {
    min_pixel(configuration.filenames[0] );
}

else if ( strncmp( configuration.command, "max_component", 14 ) == 0 ) {
    char component=configuration.arguments[0][0];
    max_component(configuration.filenames[0], component);
}
else if ( strncmp( configuration.command, "min_component", 14 ) == 0 ) {
    char component=configuration.arguments[0][0];
    min_component(configuration.filenames[0], component);
}

else if ( strncmp( configuration.command, "stat_report", 12 ) == 0 ) {
    stat_report(configuration.filenames[0]);
}

else if ( strncmp( configuration.command, "print_pixel", 12 ) == 0 ) {
    int x = atoi(configuration.arguments[0]);
    int y = atoi(configuration.arguments[1]);
    print_pixel(configuration.filenames[0], x, y);
}

else if ( strncmp( configuration.command, "color_green", 11) == 0) {
        color_green(configuration.filenames[0]);
    }

  return 0;
}
