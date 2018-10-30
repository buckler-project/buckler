CC      = g++
SUFFIX  = .cc
CFLAGS  = -g -Wall -std=c++17 -shared -fPIC
LFLAGS  = -lgtest -lpthread -lboost_filesystem -lboost_system
SOURCE  = ./src/sample.cc
TARGET  = ./bin/libsample.so

build: $(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) $(LFLAGS) -o $(TARGET)   

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
