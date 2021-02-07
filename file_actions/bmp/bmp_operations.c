#include "bmp_operations.h"

////macros (choose type_identification)
//#define PRI_SPECIFIER(e) (_Generic( (e), uint16_t : "%" PRIu16, uint32_t: "%" PRIu32, default: "NOT IMPLEMENTED" ))
//
//#define PRINT_FIELD( t, name ) \
//    fprintf( f, "%-17s: ",  # name ); \
//    fprintf( f, PRI_SPECIFIER( header-> name ) , header-> name );\
//    fprintf( f, "\n");

#define ID_BMP 0x4D42
#define SIZE 40
#define BIT_COUNT 24

static uint32_t get_padding(const size_t width) {
    size_t width_in_bytes = width * sizeof(struct pixel);
    if (width_in_bytes % 4)
        return 4 - (width_in_bytes % 4);
    return 0;
}

static struct bmp_header create_bmp_header(const struct image* img) {
    struct bmp_header h = {0};

    h.bfType = ID_BMP;
    h.bfileSize = sizeof(struct bmp_header)  +
            (sizeof(struct pixel) * img->width + get_padding(img->width)) * img->height;
    h.bfReserved = 0;
    h.bOffBits = sizeof(struct bmp_header);  // ??
    h.biSize = SIZE;
    h.biWidth = img->width;
    h.biHeight = img->height;
    h.biPlanes = 1;
    h.biBitCount = BIT_COUNT;
    h.biCompression = 0;
    h.biSizeImage = img->width * img->height * sizeof(struct pixel);
    h.biXPelsPerMeter = 0;
    h.biYPelsPerMeter = 0;
    h.biClrUsed = 0;
    h.biClrImportant = 0;
    return h;
}

static bool read_header( FILE* f, struct bmp_header* header ) {
    return fread( header, sizeof( struct bmp_header ), 1, f );
}

// --------------- read_from_bmp ----------------//

static enum read_status check_bmp_header( const struct bmp_header* header ) {
    if (header->bfType != ID_BMP)
        return READ_INVALID_SIGNATURE;

    if (header->biBitCount != BIT_COUNT)
        return READ_INVALID_BITS;

    return READ_OK;
}

enum read_status from_bmp(FILE* in, struct image* img) {
    struct bmp_header header = {0};

    if (!read_header( in, &header ))
        return READ_INVALID_HEADER;

    enum read_status check_status = check_bmp_header(&header);
    if (check_status != READ_OK)
        return check_status;

    *img = create_empty_image(header.biWidth, header.biHeight);
    const uint32_t padding = get_padding(img->width);

    for (size_t i = 0; i < img->height; i++) {
        if (fread(img->data + i * img->width, sizeof(struct pixel), img->width, in) != img->width) {
            free_image(img);
            return READ_INVALID_DATA;
        }
        if (fseek(in, padding, SEEK_CUR)) {
            free_image(img);
            return READ_INVALID_DATA;
        }
    }
    return READ_OK;
}

/*-----------------------write_to_bmp--------------------*/

enum write_status to_bmp(FILE *out, struct image const* img) {
    struct bmp_header header = create_bmp_header(img);

    if (!fwrite(&header, sizeof(struct bmp_header), 1, out))
        return WRITE_HEADER_ERROR;

    const uint32_t padding = get_padding(img->width);

    for (size_t i = 0; i < img->height; i++) {
        if (fwrite(img->data + i * img->width, sizeof(struct pixel), img->width, out) != img->width)
            return WRITE_DATA_ERROR;
        if (!fwrite("0", sizeof(char) * padding, 1, out) && padding)
            return WRITE_DATA_ERROR;
    }
    return WRITE_OK;
}