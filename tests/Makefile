CC        = g++
OBJSFX    = .o
CFLAGS    = -g -Wall -std=c++17
SFLAG     = -shared -fPIC
LFLAGS    = -lgtest -lgmock -lpthread -lboost_filesystem -lboost_system -lyaml-cpp -ldl
OBJDIR    = ./obj
SIGNATURE = ./src/signature.cc ../src/base.cc ../src/signature.hpp
UTILS     = ./src/utils.cc ../src/base.cc ../src/utils.hpp


signatures:
	$(CC) $(SIGNATURE) $(CFLAGS) $(LFLAGS) -o ./bin/signatures

utils:
	$(CC) $(UTILS) $(CFLAGS) $(LFLAGS) -o ./bin/utils

clean:
	rm -f ./bin/*

