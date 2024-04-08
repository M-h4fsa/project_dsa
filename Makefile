# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g 

# Project settings
TARGET = myprogram
SOURCES = main.c 
OBJECTS = $(SOURCES:.c=.o)
HEADERS = readAnimal.h read_id.h structures.h CRUD.h PopulateStruct.h invoice.h ReadFromUsr.h password.h 

# Library settings
LIB_DIR = /usr
INCLUDES = -I$(LIB_DIR)/include

# Compile and assemble C source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link all object files with external libraries to make the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -L$(LIB_DIR)/lib -o $(TARGET) $(LIBS)

# Phony targets for cleaning and running
.PHONY: clean run

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)


