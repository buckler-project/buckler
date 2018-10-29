CC      = g++
CFLAGS  = -g -Wall -std=c++17 -fPIC
LFLAGS  = -lpthread -lboost_filesystem -lboost_system
SRCSFX  = .cc
OBJSFX  = .o
SRCDIR  = ./src
OBJDIR  = ./obj
SOURCES = $(wildcard $(SRCDIR)/*$(SRCSFX))
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:$(SRCSFX)=$(OBJSFX))))
TARGET  = ./bin/libbuckler.a


$(TARGET): $(OBJECTS)
	ar r $(TARGET) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%$(OBJSFX): $(SRCDIR)/%$(SRCSFX)
	$(CC) $(CFLAGS) $(FLAGS) -o $@ -c $<

obj_clean:
	-rm -f $(TARGET)

clean:
	-rm -f $(TARGET) $(OBJECTS)
