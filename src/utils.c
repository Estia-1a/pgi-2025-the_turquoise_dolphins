#include <stdio.h>
#include <stdlib.h>
#include <estia-image.h>
#include "utils.h"
#include <stddef.h> // pour NULL

pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y) {
    if (data == NULL) {
        return NULL;
    }
    if (x >= width || y >= height) {
        return NULL;
    }

    unsigned int index = (y * width + x) * 3;
    return (pixelRGB*) &data[index];
}

void print_pixel(const char *source_path, int x, int y) {
    unsigned char* data = NULL;
    int WIDTH, HEIGHT, channel_count;

    // read_image_data retourne 0 en cas d'échec
    if (!read_image_data(source_path, &data, &WIDTH, &HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur : impossible de charger l'image %s\n", source_path);
    }

    pixelRGB* pixel = get_pixel(data, WIDTH, HEIGHT, x, y);
    if (pixel == NULL) {
        fprintf(stderr, "Erreur : coordonnées (%d, %d) hors de l'image (%d x %d)\n", x, y, WIDTH, HEIGHT);
        free_image_data(data); // libération via la fonction fournie
    }

    printf("print_pixel (%d,%d) : %d,%d,%d\n", x, y, pixel->R, pixel->G, pixel->B);

    // Libère la mémoire allouée dynamiquement par read_image_data
    free_image_data(data);
}
