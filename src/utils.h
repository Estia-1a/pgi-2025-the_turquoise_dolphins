#ifndef UTILS_H
#define UTILS_H
#include <stddef.h>
#include <stdio.h>

/**
 * @brief Here, you have to define pixelRGB struct and its functions:
 * - pixel* getPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y );
 * - void setPixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y, pixelRGB* pixel);
 *
*/


// Définition d'un pixel RVB
typedef struct _pixelRGB {
    unsigned char R;
    unsigned char G;
    unsigned char B;
} pixelRGB;

/*
 * Retourne un pointeur vers le pixel (x, y) dans le tableau de données image `data`,
 * ou NULL si `data` est NULL ou si (x, y) est hors des limites de l'image.
 */
pixelRGB* get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y);

#endif // UTILS_H
