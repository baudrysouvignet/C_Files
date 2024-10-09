CC = gcc
CFLAGS = -Wall -g

# Trouve tous les fichiers .c dans le répertoire courant et ses sous-répertoires
SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

TARGET = nom_du_programme

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean