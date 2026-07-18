CC = gcc
FLAGS = -Wall -Werror -Wextra -g -std=c11

MAIN_DIR = .
BUILD_DIR = ../build

MODULE_FILE = dmanager_module.c
LIST_FILE = list.c
LISTTEST_FILE = list_test.c
STACK_FILE = stack.c
STACKTEST_FILE = stack_test.c
PRINT_FILE = print_module.c
MAIN_FILE = main_module_entry_point.c
DOC_FILE = documentation_module.c

TARGET1 = $(BUILD_DIR)/Quest_1
TARGET2 = $(BUILD_DIR)/Quest_2
TARGET3 = $(BUILD_DIR)/Quest_3
TARGET4 = $(BUILD_DIR)/Quest_4
TARGET5 = $(BUILD_DIR)/Quest_5

all: door_struct list_test stack_test print_module documentation_module

door_struct: $(MODULE_FILE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(MODULE_FILE) -o $(TARGET1)

list_test: $(LIST_FILE) $(LISTTEST_FILE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(LIST_FILE) $(LISTTEST_FILE) -o $(TARGET2)

stack_test: $(STACK_FILE) $(STACKTEST_FILE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(STACK_FILE) $(STACKTEST_FILE) -o $(TARGET3)

print_module: $(MAIN_FILE) $(PRINT_FILE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(MAIN_FILE) $(PRINT_FILE) -o $(TARGET4)

documentation_module: $(MAIN_FILE) $(PRINT_FILE) $(DOC_FILE)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(MAIN_FILE) $(PRINT_FILE) $(DOC_FILE) -o $(TARGET5)

check:
	find . -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -n {} +

clean:
	rm -rf $(BUILD_DIR)

rebuild:
	clean all

.PHONY: all door_struct list_test stack_test print_module documentation_module clean rebuild check
