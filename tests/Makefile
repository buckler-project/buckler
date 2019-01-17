CC      = g++
OBJSFX  = .o
CFLAGS  = -g -Wall -std=c++17
SFLAG   = -shared -fPIC
LFLAGS  = -lgtest -lgmock -lpthread -lboost_filesystem -lboost_system -lyaml-cpp -ldl
OBJDIR  = ./obj
SOURCE  = ./src/utils.cc ../src/base.cc ../src/utils.hpp
OBJECT  = $(wildcard $(OBJDIR)/*$(OBJSFX))
TARGET  = ./bin/utils

utils:
	$(CC) $(SOURCE) $(CFLAGS) $(LFLAGS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
