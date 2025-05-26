#include <stdio.h>

#include "features.h"
#include "utils.h"
#include <stdlib.h>

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");

}

int dimension(const char *source_path, int *WIDTH, int *HEIGHT) {
    unsigned char *data = NULL;
    int channel_count;
    

    if (!read_image_data(source_path, &data, WIDTH, HEIGHT, &channel_count)) {
        fprintf(stderr, "Erreur de lecture de l'image : %s\n", source_path);
        return 0;
    }

    printf("Dimensions de l'image : %d, %d\n", *WIDTH, *HEIGHT);

    free(data);
    return 1;
}