# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Include directories
INCLUDE_DIRS = \
    -I./csvlib \
    -I./MCAL/Adc \
    -I./MCAL/Can \
    -I./MCAL/Dio \
    -I./MCAL/Pwm \
	-I./IOHWAB

# Object directory
OBJDIR = bin
TARGET = $(OBJDIR)/ecu

# Source files (quét toàn bộ .c trong csvlib + MCAL/*/ + main.c)
SRC = $(wildcard ./csvlib/*.c) \
      $(wildcard ./MCAL/*/*.c) \
	  $(wildcard ./IOHWAB/*.c) \
      ./main.c

# Object files (đưa vào OBJDIR với cùng cấu trúc thư mục)
OBJ = $(patsubst ./%.c, $(OBJDIR)/%.o, $(SRC))

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	@echo "Linking objects into $@ ..."
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build successful!"

# Compile
$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@
	@echo "Compiled: $<"

# Run
.PHONY: run
run: $(TARGET)
	@echo "Running program..."
	./$(TARGET)

# Clean
.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -rf $(OBJDIR)
	@echo "Done."
