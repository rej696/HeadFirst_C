run: build
	./build/test

build: src/main.c lib include/encrypt.h include/checksum.h
	gcc src/main.c -I ./include -L ./lib -l hfsecurity -o build/test

lib: lib/libhfsecurity.a

lib/libhfsecurity.a: build/encrypt.o build/checksum.o init
	ar -rcs lib/libhfsecurity.a build/encrypt.o build/checksum.o

include/encrypt.h: src/encrypt.h
	cp src/encrypt.h include/encrypt.h

build/encrypt.o: src/encrypt.c init
	gcc -c src/encrypt.c -o build/encrypt.o

include/checksum.h: src/checksum.h
	cp src/checksum.h include/checksum.h

build/checksum.o: src/encrypt.c init
	cp src/checksum.h include/checksum.h
	gcc -c src/checksum.c -o build/checksum.o

init:
	mkdir -p build
	mkdir -p lib
	mkdir -p include

clean:
	rm -rf build
	rm -rf lib
	rm -rf include
	
