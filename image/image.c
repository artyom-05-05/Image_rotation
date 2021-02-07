#include "image.h"

struct image create_empty_image(uint64_t width, uint64_t height) {
    struct pixel* pixels = malloc(width * height * sizeof(struct pixel));
    *pixels = (struct pixel) {0};
    return (struct image){.width = width, .height = height, .data = pixels};
}

void free_image(struct image* img) {
    free(img->data);
}

struct pixel* get_pixel(const struct image* img, uint64_t x, uint64_t y) {
    return &img->data[y * img->width + x];
}

void set_pixel(struct image* img, uint64_t x, uint64_t y, struct pixel p) {
    img->data[y * img->width + x] = p;
}
