#include <estia-image.h>
#include<stdio.h>
#include "utils.h"

/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    if (!data || x>=width || y>=height){
        return NULL;
    }
    else {
        unsigned int index = (y * width + x) * n;
        return (pixelRGB *) &data[index];
    }
}
void print_pixel(char *source_path, int x, int y)
{
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    pixelRGB* pixel;
    pixel = get_pixel(data, width, height, channel_count, x, y);
    printf("print_pixel (%d,%d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
    free_image_data(data);
}

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y ){
    if (!data || x>=width || y>=height){
        return NULL;
    }
    else {
        unsigned int index = (y * width + x) * n;
        return (pixelRGB *) &data[index];
    }
}
void print_pixel(char *source_path, int x, int y)
{
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    pixelRGB* pixel;
    pixel = get_pixel(data, width, height, channel_count, x, y);
    printf("print_pixel (%d,%d): %d, %d, %d", x, y, pixel->R, pixel->G, pixel->B);
    free_image_data(data);
}