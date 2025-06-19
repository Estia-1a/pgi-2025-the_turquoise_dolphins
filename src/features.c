#include "features.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <estia-image.h>

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");

}

void dimension(const char *source_path, int *WIDTH, int *HEIGHT) {
    unsigned char *data = NULL;
    int channel_count;
    

    if (!read_image_data(source_path, &data, WIDTH, HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
    }

    printf("dimension de l'image : %d, %d\n", *WIDTH, *HEIGHT);

    free(data);
}

void first_pixel(const char *source_path){
    unsigned char *data = NULL; 
    int WIDTH, HEIGHT, channel_count; 

    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
    }

    unsigned char r = data[0];
    unsigned char g = data[1];
    unsigned char b = data[2];

    printf("first_pixel: %d, %d, %d\n", r, g, b);

    free(data);
}

void tenth_pixel(const char *source_path){
    unsigned char *data = NULL; 
    int WIDTH, HEIGHT, channel_count; 

    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
    }

    unsigned char r = data[27];
    unsigned char g = data[28];
    unsigned char b = data[29];

    printf("first_pixel: %d, %d, %d\n", r, g, b);

    free(data);
}

void second_line(const char *source_path){
    unsigned char *data = NULL; 
    int WIDTH, HEIGHT, channel_count; 

    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
    }
    
    int index = 3*WIDTH;
    unsigned char r = data[index];
    unsigned char g = data[index+1];
    unsigned char b = data[index+2];

    printf("second_line: %d, %d, %d\n", r, g, b);

    free(data);
}