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
    printf("first_pixel: %d,%d,%d", data[0], data[1], data[2]);

    }


void tenth_pixel(char *source_path)
{
    unsigned char *data;
    int width, height, channels;

read_image_data(source_path, &data, &width, &height, &channels);
        printf("tenth_pixel: %d,%d,%d", data[27], data[28], data[29]);
        free_image_data(data);
}


 void second_line(char *source_path)
 {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    printf("second_line: %d,%d,%d", data[3*width], data[3*width+1], data[3*width+2]);
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

void min_pixel(char *source_path){
    unsigned char *data, r, g, b, minr, ming, minb;
    int width, height, channels, sum, minsum=256*3+1, minx, miny;
    read_image_data(source_path, &data, &width, &height, &channels);
        for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * channels;
        r = data[idx];
        g = data[idx+1];
        b = data[idx+2];
        sum= r + g + b;
        if (sum<minsum){
            minsum=sum;
            minx=x;
            miny=y;
            minr=r;
            ming=g;
            minb=b;
            
        }
    }
}
    printf("min_pixel (%d, %d): %d, %d, %d\n", minx, miny, minr, ming, minb);
}


void max_component(char *source_path, char component){
        unsigned char *data, rgb, maxrgb=0;
    int width, height, channels,maxx=0, maxy=0, offset;
    read_image_data(source_path, &data, &width, &height, &channels);
        if (component == 'R') offset = 0;
    else if (component == 'G') offset = 1;
    else if (component == 'B') offset = 2;
    else {
        fprintf(stderr, "Invalid component. Use R, G, or B.\n");
        return;
    }
            for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * channels;
        rgb = data[idx+offset];
        if (rgb>maxrgb){
            maxx=x;
            maxy=y;
            maxrgb=rgb;
        }
    }
}
printf("max_component %c (%d, %d): %d\n",component, maxx, maxy, maxrgb);
}


void stat_report(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    FILE *f = fopen("stat_report.txt", "w");
    if (!f) {
        printf("Erreur lors de l'ouverture\n");
        return;
    }

    int maxsum = -1, minsum = 256 * 3 + 1;
    int maxx, maxy, minx, miny;
    unsigned char maxr, maxg, maxb, minr, ming, minb;


    unsigned char maxR = 0, maxG = 0, maxB = 0;
    unsigned char minR = 255, minG = 255, minB = 255;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * channels;

            unsigned char r = data[idx];
            unsigned char g = data[idx + 1];
            unsigned char b = data[idx + 2];

            int sum = r + g + b;

            if (sum > maxsum) {
                maxsum = sum;
                maxx = x;
                maxy = y;
                maxr = r;
                maxg = g;
                maxb = b;
            }

            if (sum < minsum) {
                minsum = sum;
                minx = x;
                miny = y;
                minr = r;
                ming = g;
                minb = b;
            }

            if (r > maxR) maxR = r;
            if (g > maxG) maxG = g;
            if (b > maxB) maxB = b;

            if (r < minR) minR = r;
            if (g < minG) minG = g;
            if (b < minB) minB = b;
        }
    }

    fprintf(f, "max_pixel (%d, %d): %d, %d, %d\n\n", maxx, maxy, maxr, maxg, maxb);
    fprintf(f, "min_pixel (%d, %d): %d, %d, %d\n\n", minx, miny, minr, ming, minb);
    fprintf(f, "max_component R: %d\n", maxR);
    fprintf(f, "max_component G: %d\n", maxG);
    fprintf(f, "max_component B: %d\n\n", maxB);
    fprintf(f, "min_component R: %d\n", minR);
    fprintf(f, "min_component G: %d\n", minG);
    fprintf(f, "min_component B: %d\n", minB);

    fclose(f);
}