#include "global_header.h"

unsigned int *alloc_image(int width, int height)
{
    unsigned int *image;

    if (!(image = (unsigned int *)malloc(sizeof(unsigned int) * width * height)))
       exit_with_msg("Failed To malloc");
    return (image);
}