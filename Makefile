CC      = g++
SUFFIX  = .cc
CFLAGS  = -g -Wall -ldl -std=c++17
LFLAGS  = -lpthread -lboost_filesystem -lboost_system
SOURCE  = ./src/buckler.cc
TARGET  = ./bin/buckler
TEST_SRC   = ./tests/src/lib.cc
TEST_LIB   = ./tests/lib/lib.so
TEST_FLAGS = -g -Wall --shared

build: $(TEST_LIB) $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS) $(LFLAGS)

$(TEST_LIB): $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $(TEST_LIB) $(TEST_FLAGS) 

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET)

rebuild:
	make clean && make build
