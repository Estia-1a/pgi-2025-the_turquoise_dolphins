#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();

void dimension(const char *filename, int *WIDTH, int *HEIGHT);

void first_pixel(const char *source_path);

void tenth_pixel(const char *source_path);

void second_line(const char *source_path);

void print_pixel(const char *source_path, int x, int y);

void min_component(const char *source_path, char *component);

void max_component(const char *source_path, char *component);

#endif

