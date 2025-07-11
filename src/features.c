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

int read_image_data(const char *path, unsigned char **data, int *width, int *height, int *channel_count);

void max_component(const char *source_path, const char *component) {
    int width, height, channel_count;
    unsigned char *data;

    if (!read_image_data(source_path, &data, &width, &height, &channel_count)) {
        printf("Erreur lecture image\n");
        return;
    }

    int max_val = -1;
    int max_x = 0, max_y = 0;

  
    int comp_index = -1;
    if (strcmp(component, "R") == 0) comp_index = 0;
    else if (strcmp(component, "G") == 0) comp_index = 1;
    else if (strcmp(component, "B") == 0) comp_index = 2;
    else {
        printf("Composante inconnue: %s\n", component);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * channel_count;
            int val = data[pixel_index + comp_index];
            if (val > max_val) {
                max_val = val;
                max_x = x;
                max_y = y;
            }
        }
    }

    printf("max_component %s (%d, %d): %d\n", component, max_x, max_y, max_val);
}


void min_component(const char *source_path, const char *component){
    unsigned char *data = NULL;
    int WIDTH, HEIGHT, channel_count, x, y, component_val;

    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
        return;
    }

    int min_component_valeur = 765;
    int min_x = 0;
    int min_y = 0;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int pixel_num = (y * WIDTH + x) * channel_count;
            int R = data[pixel_num];
            int G = data[pixel_num + 1];
            int B = data[pixel_num + 2];

            if (strcmp(component, "R") == 0) {
                component_val = R;
            } else if (strcmp(component, "G") == 0) {
                component_val = G;
            } else if (strcmp(component, "B") == 0) {
                component_val = B;
            } else {
                printf("Erreur de lecture de la composante.\n");
                free(data);
                return;
            }

            if (component_val < min_component_valeur) {
                min_component_valeur = component_val;
                min_x = x;
                min_y = y;
            }
        }
    free (data);
    }

    printf("min_component %s (%d,%d): %d\n", component, min_x, min_y, min_component_valeur);

    free(data);
}   
void color_red(char* source_path){
    int width, height, nbChannels;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &nbChannels);
    int y;
    int x;
    for (y = 0; y < height; y++){
        for (x=0; x < width; x++){
            data[y*width*3 + x*3+1] = data[y*width*3 + x*3+0]; // Vert = Rouge
            data[y*width*3 + x*3+2] = data[y*width*3 + x*3+0]; // Bleu = Rouge
        }
    }
    

}

void rotate_cw(char *source_path) {
    int width, height, nbChannels;
    unsigned char *source_data;
    unsigned char *target_data;

    if (read_image_data(source_path, &source_data, &width, &height, &nbChannels)) {
        target_data = (unsigned char *)malloc(width * height * nbChannels * sizeof(unsigned char));

        int target_width = height;
        int target_height = width;

        int y, x;
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                int source_pixel_index = (y * width + x) * nbChannels;
                int target_pixel_index = ((x * target_width) + (target_width - 1 -y)) * nbChannels;
                target_data[target_pixel_index] = source_data[source_pixel_index];
                target_data[target_pixel_index + 1] = source_data[source_pixel_index + 1];
                target_data[target_pixel_index + 2] = source_data[source_pixel_index + 2];

                if (nbChannels == 4) {
                    target_data[target_pixel_index + 3] = source_data[source_pixel_index + 3];
                }
            }
        }
        write_image_data("image_out.bmp", target_data, target_width, target_height);

        free(source_data);
        free(target_data);
    }
}

void rogner_bas(char* source_path) {
    int width, height, nbChannels;
    unsigned char* source_data;
    read_image_data(source_path, &source_data, &width, &height, &nbChannels);
    unsigned char* target_data = (unsigned char *)malloc(3*(height)*(width));
    int i = (3*(width)*(height)) - (3*(width)*(height))/4;
    int j = (3*(width)*(height));
    while (i<j) {
        target_data[i] = source_data[i];
        target_data[i+1] = source_data[i+1];
        target_data[i+2] = source_data[i+2];
        i = i+3;
    }
    write_image_data("image_out.bmp", target_data, width, height/4);
}

void rogner_haut (char* source_path) {
    int width, height, nbChannels;
    unsigned char* source_data;
    read_image_data(source_path, &source_data, &width, &height, &nbChannels);
    unsigned char* target_data = (unsigned char*)malloc(3*(height)*(width));
    int i=0;
    int j=(3*(width)*(height))/4;
    while (i<j) {
        target_data[i]=source_data[i];
        target_data[i+1]=source_data[i+1];
        target_data[i+2]=source_data[i+2];
        i=i+3;
    }
    write_image_data("image_out.bmp", target_data, width, height/4);
}

