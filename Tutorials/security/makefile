run: main.c
	./build/test

main.c: lib
	gcc main.c -L ./lib -l hfsecurity -o build/test

lib: lib/libhfsecurity.a

lib/libhfsecurity.a: build/encrypt.o build/checksum.o init
	ar -rcs lib/libhfsecurity.a build/encrypt.o build/checksum.o

build/encrypt.o: init
	gcc -c encrypt.c -o build/encrypt.o

build/checksum.o: init
	gcc -c checksum.c -o build/checksum.o

init: clean
	mkdir build
	mkdir lib

clean:
	rm -r build
	rm -r lib
	
