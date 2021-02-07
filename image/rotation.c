#include "rotation.h"

struct image rotate90degrees(const struct image* old) {
    struct image new = create_empty_image(old->height, old->width);

    for (uint64_t x = 0; x < old->width; x++) {
        for (uint64_t y = 0; y < old->height; y++)
            set_pixel(&new, y, (new.height - 1 - x), *get_pixel(old, x, y));
    }
    return new;
}
