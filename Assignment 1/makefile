CC      = g++
CFLAGS  = -Wall
LDFLAGS =
OBJFILES = main.cpp management.h management.cpp
TARGET   = assignment1.tar

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm –f $(OBJFILES) $(TARGET) *~
