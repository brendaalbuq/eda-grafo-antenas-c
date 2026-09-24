CC = gcc
CFLAGS = -Wall -g -Iinclude

SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
EXEC = $(BINDIR)/projeto_eda.exe

all: diretórios $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean diretórios

diretórios:
	mkdir -p $(BINDIR) $(OBJDIR)

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/*.exe

run:
	$(BINDIR)/projeto_eda.exe
