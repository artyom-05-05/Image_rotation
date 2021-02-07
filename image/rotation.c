#include "rotation.h"

struct image rotate90degrees(const struct image* old) {
    struct image new = new_image(old->height, old->width);

    for (size_t x = 0; x < old->height; x++) {
        for (size_t y = 0; y < old->width; y++)
            set_pixel(&new, y, (result.height - 1 - x), *get_pixel(old, x, y));
    }
    return new;
}