MAKEFLAGS += -s

SRC_DIR := src
OUT_DIR := out

CC = gcc
CFLAGS = -std=c2x

# Target to build and run a specific C source file
run: 
	@$(MAKE) $(OUT_DIR)/$(FILE)
	#@echo "Running $(OUT_DIR)/$(FILE)..."
	@./$(OUT_DIR)/$(FILE)

# General rule to compile any C file in src folder and put binary in corresponding out folder
$(OUT_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) # Creates the output directory if it doesn't exist
	@gcc -o $@ $<       # Compiles source file into out folder with same structure
	#@echo "Compiled $< to $@"

.PHONY: run

clean:
	rm -r out
