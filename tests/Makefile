CC        = g++
OBJSFX    = .o
CFLAGS    = -g -Wall -std=c++17
SFLAG     = -shared -fPIC
LFLAGS    = -lgtest -lgmock -lpthread -lboost_filesystem -lboost_system -lyaml-cpp -ldl
OBJDIR    = ./obj
BUCKLER   = ./src/buckler.cc ../obj/*
SIGNATURE = ./src/signature.cc ../obj/base.o ../obj/signature.o
SCANNER   = ./src/scanner.cc ../obj/base.o ../obj/signature.o ../obj/scanner.o
UTILS     = ./src/utils.cc ../obj/base.o ../obj/utils.o

buckler:
	$(CC) $(BUCKLER) $(CFLAGS) $(LFLAGS) -o ./bin/buckler

scanners:
	$(CC) $(SCANNER) $(CFLAGS) $(LFLAGS) -o ./bin/scanners

signatures:
	$(CC) $(SIGNATURE) $(CFLAGS) $(LFLAGS) -o ./bin/signatures

utils:
	$(CC) $(UTILS) $(CFLAGS) $(LFLAGS) -o ./bin/utils

clean:
	rm -f ./bin/*

