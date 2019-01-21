CC        = g++
OBJSFX    = .o
CFLAGS    = -g -Wall -std=c++17
SFLAG     = -shared -fPIC
LFLAGS    = -lgtest -lgmock -lpthread -lboost_filesystem -lboost_system -lyaml-cpp -ldl
OBJDIR    = ./obj
BUCKLER   = ./src/buckler.cc ../src/*
SIGNATURE = ./src/signature.cc ../src/base.cc ../src/signature.hpp
SCANNER   = ./src/scanner.cc ../src/base.cc ../src/signature.cc ../src/scanner.cc
UTILS     = ./src/utils.cc ../src/base.cc ../src/utils.hpp

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

