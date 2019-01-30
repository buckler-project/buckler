CC      = g++
SUFFIX  = .cc
CFLAGS  = -g -Wall -std=c++17
SOURCE  = ./src/sample.cc
TARGET  = ./bin/libsample.so
TEST_SOURCE  = ./src/tests.cc
TEST_TARGET  = ./bin/tests

build: $(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) -shared -fPIC -o $(TARGET)

test: $(TESTS)
	$(CC) $(TEST_SOURCE) $(CFLAGS ) -lgtest -o $(TEST_TARGET)   

clean:
	rm -f $(TARGET) $(TRUE_TARGET) $(FALSE_TARGET) 

rebuild:
	make clean && make build
