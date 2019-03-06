CC       = g++
CFLAGS   = -std=c++17 -fPIC
LFLAGS   = -lpthread -lboost_system -lboost_filesystem -lyaml-cpp -ldl
SRCSFX   = .cc
OBJSFX   = .o
HDRSFX   = .hpp
SRCDIR   = ./src
OBJDIR   = ./obj
SOURCES  = $(wildcard $(SRCDIR)/*$(SRCSFX))
OBJECTS  = $(addprefix $(OBJDIR)/, $(notdir $(SOURCES:$(SRCSFX)=$(OBJSFX))))
HEADERS  = $(wildcard $(SRCDIR)/*$(HDRSFX)) ./src/utils.cc
TARGET   = ./bin/libbuckler.so
LIB_PATH = /usr/lib/libbuckler.so
HDR_PATH = /usr/include/buckler

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -shared -o $(TARGET)

install:
	install $(TARGET) $(LIB_PATH)\
	&& install -D -t $(HDR_PATH) $(HEADERS)

$(OBJDIR)/%$(OBJSFX): $(SRCDIR)/%$(SRCSFX)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f $(TARGET) $(OBJECTS)
