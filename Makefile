#Grupo:
#Bruno Menegaz Acerbi
#Gustavo Dutra Santolin
#Leonardo Franco Emerick Albergaria 

TARGET := a.out
LIBS := -lm
OBJDIR := obj/
SRCDIR := src/
INCLUDEDIR := include/
INCLUDE_PATHS := -Iinclude
CLI := client/main.c
CC := gcc

all: $(TARGET)

SRC = $(wildcard $(SRCDIR)*.c)
HEADERS = $(wildcard $(INCLUDEDIR)*.h)

CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))

OBJECTS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJECTS += $(CLIENT).o

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

$(CLIENT).o: $(CLI)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<
  

$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE_PATHS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f $(OBJDIR)*.o
	-rm -f $(TARGET)