encrypt.o: encrypt.c encrypt.h
	clang -c encrypt.c

message_hider.o: message_hider.c encrypt.h
	clang -c message_hider.c

hide_message: message_hider.o encrypt.o
	clang message_hider.o encrypt.o -o hide_message
