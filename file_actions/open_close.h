#ifndef ASSIGNMENT_IMAGE_ROTATION_OPEN_CLOSE_H
#define ASSIGNMENT_IMAGE_ROTATION_OPEN_CLOSE_H

#include <stdio.h>

enum open_status {
    OPEN_OK = 0,
    OPEN_ERROR = 1
};

enum open_status open_file(FILE** file, const char* path, const char *mode) ;

enum close_status {
    CLOSE_OK = 0,
    CLOSE_ERROR = 1
};

enum close_status close_file(FILE** file);

#endif //ASSIGNMENT_IMAGE_ROTATION_OPEN_CLOSE_H
