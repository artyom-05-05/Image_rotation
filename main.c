#include "utils/util.h"
#include "image/rotation.h"

void usage() {
    fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main( int argc, char** argv ) {
    if (argc != 3) usage();
    if (argc < 3) err("Not enough arguments \n" );
    if (argc > 3) err("Too many arguments \n" );

    FILE* input;
    FILE* output;

    check_open(open_file(&input, argv[1], "rb"));
    check_open(open_file(&output, argv[2], "wb"));

    struct image img = {0};

    check_read(from_bmp(input, &img));
    struct image rotated = rotate90degrees(&img);
    check_write(to_bmp(output, &rotated));

    check_close(close_file(&input));
    check_close(close_file(&output));

    return 0;
}