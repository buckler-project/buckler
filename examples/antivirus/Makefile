CC      = g++
CFLAGS  = -g -Wall -std=c++17 -fPIC
LFLAGS  = -lpthread -lboost_system -lboost_filesystem -lyaml-cpp -ldl -lbuckler
SOURCE  = ./src/antivirus.cc
TARGET  = ./bin/antivirus


$(TARGET): $(SOURCE)
	$(CC) $(LFLAGS) $(CFLAGS) $(SOURCE) -o $(TARGET) 

clean:
	-rm -f $(TARGET) $(OBJECTS)
