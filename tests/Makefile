CC      = g++
OBJSFX  = .o
CFLAGS  = -g -Wall -std=c++17
SFLAG   = -shared -fPIC
LFLAGS  = -lgtest -lpthread -lboost_filesystem -lboost_system -ldl
OBJDIR  = ../obj
SOURCE  = ./src/tests.cc
OBJECT  = $(wildcard $(OBJDIR)/*$(OBJSFX))
TARGET  = ./bin/tests

build:
	$(CC) $(SOURCE) $(OBJECT) $(CFLAGS) $(LFLAGS) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
