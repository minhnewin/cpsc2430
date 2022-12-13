CC      = g++
CFLAGS  = -Wall
LDFLAGS =
OBJFILES = assignment3.cpp BST.cpp BST.h
TARGET   = assignment3.tar

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f *o main
