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
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
 
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    const char *source_path = "./images/input/image.jpeg";
    int WIDTH, HEIGHT; 
    
    dimension(source_path, &WIDTH, &HEIGHT);
  }

  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    const char *source_path = "./images/input/image.jpeg";    
    first_pixel(source_path);
  }

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    const char *source_path = "./images/input/image.jpeg";    
    tenth_pixel(source_path);
  }


  if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    const char *source_path = "./images/input/image.jpeg"; 
    second_line(source_path);
    
  }

  if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
    if (argc < 5) {
      fprintf(stderr, "Usage: %s -f images/input/image.jpeg> -c print_pixel <x> <y>\n", argv[0]);
    }
    const char *source_path = argv[2]; // -f chemin de l'image
    int x = atoi(argv[4]);             // x
    int y = atoi(argv[5]);             // y

    print_pixel(source_path,x,y);
  } 
  
  if ( strncmp( configuration.command, "min_component", 13 ) == 0 ) {
    const char *source_path = "./images/input/image.jpeg";
    char component;
    min_component(source_path,component);
  }
  return 0;


  if ( strncmp( configuration.command, "max_component", 13 ) == 0 ) {
    const char *source_path = "./images/input/image.jpeg";
    char component;
    max_component(source_path,component);
  }
  return 0;
}
