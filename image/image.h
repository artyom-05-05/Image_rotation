#ifndef ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
#define ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

#include <inttypes.h>
#include <malloc.h>

struct pixel { uint8_t b, g, r; };

struct image {
    uint64_t width, height;
    struct pixel* data;
};

struct image create_empty_image(uint64_t width, uint64_t height);
void free_image(struct image* img);

struct pixel* get_pixel(const struct image* img, uint64_t x, uint64_t y);
void set_pixel(struct image* img, uint64_t x, uint64_t y, struct pixel p);

#endif //ASSIGNMENT_IMAGE_ROTATION_IMAGE_H
