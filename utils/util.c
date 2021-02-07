#include "util.h"

_Noreturn void err(const char* message) {
    fprintf(stderr,"%s", message);
    exit(1);
}

void check_open(enum open_status status) {
    if (status != OPEN_OK)
        err("Can't open the file\n");
}

void check_close(enum close_status status) {
    if (status != CLOSE_OK)
        err("Can't close the file\n");
}

static const char* read_errors[] = {
        [READ_INVALID_SIGNATURE] = "Invalid signature of file\n",
        [READ_INVALID_BITS] = "Invalid bits per pixel of file\n",
        [READ_INVALID_HEADER] = "Header is invalid\n",
        [READ_INVALID_DATA] = "Data (pixels) are invalid\n"
};

void check_read(enum read_status status) {
    if (status != READ_OK)
        err(read_messages[status]);
}

static const char* write_errors[] = {
        [WRITE_HEADER_ERROR] = "Some problems with writing a bmp_header\n",
        [WRITE_DATA_ERROR] = "Some problems with writing data(pixels) to bmp\n"
};

void check_write(enum write_status status) {
    if (status != WRITE_OK)
        err(write_messages[status]);
}