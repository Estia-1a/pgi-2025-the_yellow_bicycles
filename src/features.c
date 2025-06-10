#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */
 void dimension(char *source_path)
 {
     unsigned char *data;
     int width, height, channels;
 
     if (read_image_data(source_path, &data, &width, &height, &channels))
     {
         printf("dimension: %d, %d\n", width, height);
     }
}

void first_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channels;

read_image_data(source_path, &data, &width, &height, &channels);
        printf("first_pixel: %d, %d, %d\n", data[0], data[1], data[2]);

    }

void tenth_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channels;

    if (read_image_data(source_path, &data, &width, &height, &channels))
    {
        int index = 9 * channels;

        printf("tenth_pixel: %d, %d, %d\n", data[index], data[index + 1], data[index + 2]);
    }
}
