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

 void second_line(char *source_path)
 {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    printf("second_line: %d, %d, %d\n", data[3*width], data[3*width+1], data[3*width+2]);
    }
void max_pixel(char *source_path){
    unsigned char *data, r, g, b, maxr, maxg, maxb;
    int width, height, channels, sum, maxsum=-1,maxx, maxy;
    read_image_data(source_path, &data, &width, &height, &channels);
        for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * channels;
        r = data[idx];
        g = data[idx+1];
        b = data[idx+2];
        sum= r + g + b;
        if (sum>maxsum){
            maxsum=sum;
            maxx=x;
            maxy=y;
            maxr=r;
            maxg=g;
            maxb=b;
            
        }
    }
}
    printf("max_pixel (%d, %d): %d, %d, %d\n", maxx, maxy, maxr, maxg, maxb);
}