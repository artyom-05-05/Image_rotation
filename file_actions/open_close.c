#include "open_close.h"

enum open_status open_file(FILE** file, const char* path, const char *mode) {
    if (!path) return OPEN_ERROR;

    *file = fopen(path, mode);
    if (*file == NULL)
        return OPEN_ERROR;
    return OPEN_OK;
}

enum close_status close_file(FILE** file) {
    if (fclose(*file) != 0)
        return CLOSE_ERROR;
    return CLOSE_OK;
}