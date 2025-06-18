#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>
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

void min_component(char *source_path, char component){
        unsigned char *data, rgb, minrgb=255;
    int width, height, channels,minx=0, miny=0, offset;
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
        if (rgb<minrgb){
            minx=x;
            miny=y;
            minrgb=rgb;
        }
    }
}
printf("min_component %c (%d, %d): %d\n",component, minx, miny, minrgb);
}


void stat_report(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    FILE *stat_report;
    stat_report = freopen("report.txt", "w",stdout);
    max_pixel(source_path);
    printf("\n");
 
    min_pixel(source_path);
    printf("\n");
 
    max_component(source_path,'R');
    printf("\n");
 
    max_component(source_path,'G');
    printf("\n");
 
    max_component(source_path,'B');
    printf("\n");
 
    min_component(source_path,'R');
    printf("\n");
 
    min_component(source_path,'G');
    printf("\n");
 
    min_component(source_path,'B');
    printf("\n");
 
    fclose(stat_report);
 
    free_image_data(data);
}

void color_green(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        data[i + 0] = 0;
        data[i + 2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_red(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        data[i + 1] = 0;
        data[i + 2] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_blue(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        data[i + 0] = 0;
        data[i + 1] = 0;
    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        unsigned char R = data[i + 0];
        unsigned char G = data[i + 1];
        unsigned char B = data[i + 2];

        unsigned char Gray = (R + G + B) / 3;
        data[i + 0] = Gray;
        data[i + 1] = Gray;
        data[i + 2] = Gray;

    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_invert(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        data[i + 0] = 255 - data[i + 0];
        data[i + 1] = 255 - data[i + 1];
        data[i + 2] = 255 - data[i + 2];

    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}

void color_gray_luminance(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    for (int i = 0; i<width * height * channels; i += channels) {
        unsigned char R = data[i + 0];
        unsigned char G = data[i + 1];
        unsigned char B = data[i + 2];

        float gray_luminance = (float)(R*0.21f + G*0.72f + B*0.07f);
        data[i + 0] = gray_luminance;
        data[i + 1] = gray_luminance;
        data[i + 2] = gray_luminance;

    }
    write_image_data("image_out.bmp", data, width, height);
    free_image_data(data);
}
void rotate_cw(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);

    int new_width = height;
    int new_height = width;
    unsigned char *rotated = malloc(new_width * new_height * channels);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_x = height - 1 - y;
                int dest_y = x;
                int dest_index = (dest_y * new_width + dest_x) * channels + c;
                rotated[dest_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", rotated, new_width, new_height);
    free_image_data(data);
    free(rotated);
}
void rotate_acw(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    int new_width = height;
    int new_height = width;
    unsigned char *rotated = malloc(new_width * new_height * channels);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_x = y;
                int dest_y = width - 1 - x;
                int dest_index = (dest_y * new_width + dest_x) * channels + c;
                rotated[dest_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", rotated, new_width, new_height);
    free_image_data(data);
    free(rotated);
}
void mirror_horizontal(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    int maxx=width;
    unsigned char *mirrored = malloc(width * height * channels);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_x = maxx-x+1;
                int dest_y = y;
                int dest_index = (dest_y * width + dest_x) * channels + c;
                mirrored[dest_index] = data[src_index];
            }
        }
    }
 
    write_image_data("image_out.bmp", mirrored, width, height);
    free_image_data(data);
    free(mirrored);
}
void mirror_vertical(char *source_path) {
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    unsigned char *mirrored = malloc(width * height * channels);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int src_index = (y * width + x) * channels + c;
                int dest_y = height - 1 - y;
                int dest_index = (dest_y * width + x) * channels + c;
                mirrored[dest_index] = data[src_index];
            }
        }
    }

    write_image_data("image_out.bmp", mirrored, width, height);
    free_image_data(data);
    free(mirrored);
}
void scale_crop(const char *source_path, int center_x, int center_y, int crop_width, int crop_height){
    unsigned char *data;
    int width, height, channels;
    read_image_data(source_path, &data, &width, &height, &channels);
    unsigned char *cropped = calloc(crop_width * crop_height * channels, 1);

    int start_x = center_x - crop_width/2;
    int start_y = center_y - crop_height/2;
     for (int y = 0; y < crop_height; y++) {
        for (int x = 0; x < crop_width; x++) {
            int src_x = start_x + x;
            int src_y = start_y + y;
            if(src_x>0 && src_x<width && src_y>0 && src_y<width){
                for (int c = 0; c < channels; c++){
                int src_index = (src_y * width + src_x) * channels + c;
                int dest_index = (y * crop_width + x) * channels + c;
                cropped[dest_index] = data[src_index];
                }
            }
        }
    }
        write_image_data("image_out.bmp", cropped, crop_width, crop_height);
    free_image_data(data);
    free(cropped);
}