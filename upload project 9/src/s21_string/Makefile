CC = gcc
CFLAGS = -Wall -Werror -Wextra
GOFLAGS = -std=c11

MAIN_DIR = .
BUILD_DIR = ../../build
SOURCE_DIR = ..

TEST_FILE = s21_string_test.c
FUNCTIONS_FILE = s21_string.c
TARGET_FILE_Q6 = $(BUILD_DIR)/Quest_6
TARGET_FILE_Q7 = $(BUILD_DIR)/Quest_7
TARGET_FILE_Q8 = $(BUILD_DIR)/Quest_8
TARGET_FILE_Q9 = $(BUILD_DIR)/Quest_9
TARGET_FILE_Q10 = $(BUILD_DIR)/Quest_10

all: $(TARGET_FILE_Q7)

strlen_tests: $(TEST_FILE) $(FUNCTIONS_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_FILE) $(FUNCTIONS_FILE) -o $(TARGET_FILE_Q6)

strcmp_tests: $(TEST_FILE) $(FUNCTIONS_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_FILE) $(FUNCTIONS_FILE) -o $(TARGET_FILE_Q7)

strcpy: $(TEST_FILE) $(FUNCTIONS_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_FILE) $(FUNCTIONS_FILE) -o $(TARGET_FILE_Q8)

strcat: $(TEST_FILE) $(FUNCTIONS_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_FILE) $(FUNCTIONS_FILE) -o $(TARGET_FILE_Q9)

strchr: $(TEST_FILE) $(FUNCTIONS_FILE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -g $(TEST_FILE) $(FUNCTIONS_FILE) -o $(TARGET_FILE_Q10)

check:
	find $(SOURCE_DIR) -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -n {} +

clean:
	rm -rf $(BUILD_DIR)

rebuild:
	clean all

.PHONY: all clean rebuild
