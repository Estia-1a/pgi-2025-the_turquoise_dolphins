#include "features.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <estia-image.h>
#include <string.h>


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














































void max_component(const char *source_path, char *component) {
    int width, height, channel_count;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channel_count)) {
        int max_component_valeur = 0;
        int max_x = 0;
        int max_y = 0;

        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int pixel_num = (y * width + x) * channel_count;
                int R = data[pixel_num];
                int G = data[pixel_num + 1];
                int B = data[pixel_num + 2];
                int component_val;

                if (strcmp(component, "R") == 0){
                    component_val = R;
                }
                else if(strcmp(component, "G") == 0){
                    component_val = G;
                }
                else if (strcmp(component, "B") == 0){
                    component_val = B;
                }
                else{
                    printf("Erreur de lecture de la composante.\n");
                }
                if (component_val > max_component_valeur) {
                    max_component_valeur = component_val;
                    max_x = x;
                    max_y = y;
                }
            }
        }
    }
}

void min_component(const char *source_path, char *component){
    unsigned char *data = NULL;
    int WIDTH, HEIGHT, channel_count, x, y, component_val;

    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
        return;
    }
    
    int min_component_valeur = 765;
    int min_x = 0;
    int min_y = 0;

    for (y=0; y<HEIGHT; y++) {
        for (x=0; x<WIDTH; x++){
            int pixel_num = (y*WIDTH + x)*channel_count;
            int R = data[pixel_num];
            int G = data[pixel_num + 1];
            int B = data[pixel_num + 2];

            if (strcmp(component, "R") == 0){
                component_val = R;
            }
            else if(strcmp(component, "G") == 0){
                component_val = G;
            }
            else if (strcmp(component, "B") == 0){
                component_val = B;
            }
            else{
                printf("Erreur de lecture de la composante.\n");
            }
            if (component_val<min_component_valeur){
                min_component_valeur = component_val;
                min_x = x;
                min_y = y;
            }
    printf("min_component %s (%d,%d): %d\n", component, min_x, min_y, min_component_valeur);
        }
    }
    

}