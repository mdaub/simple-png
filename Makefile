SRC_DIR = src
OBJ_DIR = obj
INC = include
CC = gcc
CFLAGS   = -Wall -I$(INC)
LDFLAGS  = -L. -lspng -lz
DEPS = $(INC)/png.h $(INC)/crc32.h $(INC)/crc32table.h $(INC)/codepage-437.h $(INC)/drawing.h
OBJ = crc32.o png.o drawing.o
OBJFILES = $(addprefix $(OBJ_DIR)/, $(OBJ))
TARGET   = libspng.a
EXAMPLE = example


all: $(TARGET) $(EXAMPLE)

$(TARGET): $(OBJFILES) $(DEPS)
	ar -crs $@ $(OBJFILES)
$(EXAMPLE): example.o
	$(CC) -o $@ $< $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

debug: CFLAGS += -g -DDEBUG
debug: all

clean:
	rm -f $(OBJFILES) $(TARGET) $(EXAMPLE) example.o