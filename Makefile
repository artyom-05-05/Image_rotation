CFLAGS=--std=c11 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CC=gcc

all: image_rotation

bmp_operations.o: file_actions/bmp/bmp_operations.c
	$(CC) -c $(CFLAGS) $< -o $@

open_close.o: file_actions/open_close.c
	$(CC) -c $(CFLAGS) $< -o $@

image.o: image/image.c
	$(CC) -c $(CFLAGS) $< -o $@

rotation.o: image/rotation.c
	$(CC) -c $(CFLAGS) $< -o $@

util.o: utils/util.c
	$(CC) -c $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

image_rotation: main.o open_close.o bmp_operations.o image.o rotation.o util.o
	$(CC) -o image_rotation $^
	rm -f main.o open_close.o bmp_operations.o image.o rotation.o util.o

clean:
	rm -f main.o open_close.o bmp_operations.o image.o rotation.o util.o image_rotation