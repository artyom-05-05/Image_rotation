#ifndef ASSIGNMENT_IMAGE_ROTATION_BMP_OPERATIONS_H
#define ASSIGNMENT_IMAGE_ROTATION_BMP_OPERATIONS_H

#include "../../image/image.h"
#include <stdio.h>
#include <stdbool.h>

#define FOR_BMP_HEADER( FOR_FIELD ) \
        FOR_FIELD( uint16_t,bfType)\
        FOR_FIELD( uint32_t,bfileSize)\
        FOR_FIELD( uint32_t,bfReserved)\
        FOR_FIELD( uint32_t,bOffBits)\
        FOR_FIELD( uint32_t,biSize)\
        FOR_FIELD( uint32_t,biWidth)\
        FOR_FIELD( uint32_t,biHeight)\
        FOR_FIELD( uint16_t,biPlanes)\
        FOR_FIELD( uint16_t,biBitCount)\
        FOR_FIELD( uint32_t,biCompression)\
        FOR_FIELD( uint32_t,biSizeImage)\
        FOR_FIELD( uint32_t,biXPelsPerMeter)\
        FOR_FIELD( uint32_t,biYPelsPerMeter)\
        FOR_FIELD( uint32_t,biClrUsed)\
        FOR_FIELD( uint32_t,biClrImportant)

#define DECLARE_FIELD( t, n ) t n ;

struct __attribute__((packed)) bmp_header {
    FOR_BMP_HEADER( DECLARE_FIELD )
};

enum read_status {
    READ_OK = 0,
    READ_INVALID_SIGNATURE = 1,
    READ_INVALID_BITS = 2,
    READ_INVALID_HEADER = 3,
    READ_INVALID_DATA = 4
};

enum read_status from_bmp(FILE* in, struct image* img);

enum write_status {
    WRITE_OK = 0,
    WRITE_HEADER_ERROR = 1,
    WRITE_DATA_ERROR = 2
};

enum write_status to_bmp(FILE* out, struct image const* img);

#endif //ASSIGNMENT_IMAGE_ROTATION_BMP_OPERATIONS_H
