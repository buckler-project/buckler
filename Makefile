CC      = g++
SUFFIX  = .cc
CFLAGS  = -g -Wall -ldl
SOURCE  = ./src/buckler.cc
TARGET  = ./bin/buckler
TEST_SRC   = ./tests/src/lib.cc
TEST_LIB   = ./tests/lib/lib.so
TEST_FLAGS = -g -Wall --shared

build: $(TEST_LIB) $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS)

$(TEST_LIB): $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $(TEST_LIB) $(TEST_FLAGS) 

run: $(TARGET)
	make rebuild && $(TARGET)

clean:
	rm -f $(TARGET)

rebuild:
	make clean && make build
