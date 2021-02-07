#ifndef ASSIGNMENT_IMAGE_ROTATION_UTIL_H
#define ASSIGNMENT_IMAGE_ROTATION_UTIL_H

#include "../file_actions/open_close.h"
#include "../file_actions/bmp/bmp_operations.h"
#include "stdlib.h"
#include "stdarg.h"

_Noreturn void err(const char* message);

void check_open(enum open_status status);
void check_close(enum close_status status);
void check_read(enum read_status status);
void check_write(enum write_status status);

#endif //ASSIGNMENT_IMAGE_ROTATION_UTIL_H
