#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
    Config configuration;
    parse_arguments(argc, argv, &configuration);
    check_debug_mode(configuration);
    check_file();

    if (strncmp(configuration.command, "helloworld", 10) == 0) {
        helloWorld();
    }

    if (strncmp(configuration.command, "dimension", 9) == 0) {
        const char *source_path = "./images/input/image.jpeg";
        int WIDTH, HEIGHT;
        dimension(source_path, &WIDTH, &HEIGHT);
    }

    if (strncmp(configuration.command, "first_pixel", 11) == 0) {
        const char *source_path = "./images/input/image.jpeg";
        first_pixel(source_path);
    }

    if (strncmp(configuration.command, "tenth_pixel", 11) == 0) {
        const char *source_path = "./images/input/image.jpeg";
        tenth_pixel(source_path);
    }

    if (strncmp(configuration.command, "second_line", 11) == 0) {
        const char *source_path = "./images/input/image.jpeg";
        second_line(source_path);
    }

    if (strncmp(configuration.command, "print_pixel", 11) == 0) {
        if (argc < 6) {
            fprintf(stderr, "Usage: %s -f images/input/image.jpeg -c print_pixel <x> <y>\n", argv[0]);
            return 1;
        }
        const char *source_path = argv[2]; 
        int x = atoi(argv[4]);             
        int y = atoi(argv[5]);           
        print_pixel(source_path, x, y);
    }

    if (strncmp(configuration.command, "min_component", 13) == 0) {
        const char *source_path = "./images/input/image.jpeg";
        
        min_component(source_path, "R");  
    }

    if (strncmp(configuration.command, "max_component", 13) == 0) {
        const char *source_path = "./images/input/image.jpeg";
       
        max_component(source_path, "R");
    }

    return 0;
}