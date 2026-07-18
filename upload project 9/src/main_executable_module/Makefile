CC = gcc
CFLAGS = -Wall -Werror -Wextra
GOFLAGS = -std=c11
LDFLAGS = -lm
AR = ar
ARFLAGS = rcs
DYNFLAGS = -fPIC -shared

MAIN_DIR = .
ANOTHER_DIR = ../yet_another_decision_module
LIBS_DIR = ../data_libs
MODULE_DIR = ../data_module
BUILD_DIR = ../../build

TARGET_Q3 = $(BUILD_DIR)/Quest_3
TARGET_Q4 = $(BUILD_DIR)/Quest_4
TARGET_Q5 = $(BUILD_DIR)/Quest_5

STATIC_LIB = $(BUILD_DIR)/data_stat.a
DYNAMIC_LIB = $(BUILD_DIR)/libdata_process.so

SRCS_Q3 = $(MAIN_DIR)/main_executable_module.c \
          $(ANOTHER_DIR)/decision.c \
          $(LIBS_DIR)/data_stat.c \
          $(LIBS_DIR)/data_io.c \
          $(MODULE_DIR)/data_process.c

SRCS_Q4 = $(MAIN_DIR)/main_executable_module.c \
          $(ANOTHER_DIR)/decision.c \
          $(LIBS_DIR)/data_io.c \
          $(MODULE_DIR)/data_process.c

SRCS_Q5 = $(MAIN_DIR)/main_executable_module.c \
          $(ANOTHER_DIR)/decision.c \
          $(LIBS_DIR)/data_stat.c \
          $(LIBS_DIR)/data_io.c


all: $(TARGET_Q3)


$(TARGET_Q3): $(SRCS_Q3)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GOFLAGS) -g $(SRCS_Q3) -o $(TARGET_Q3) $(LDFLAGS)


data_stat.a: $(LIBS_DIR)/data_stat.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GOFLAGS) -c $(LIBS_DIR)/data_stat.c -o $(BUILD_DIR)/data_stat.o
	$(AR) $(ARFLAGS) $(STATIC_LIB) $(BUILD_DIR)/data_stat.o
	rm -f $(BUILD_DIR)/data_stat.o

build_with_static: data_stat.a $(SRCS_Q4)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GOFLAGS) -g $(SRCS_Q4) $(STATIC_LIB) -o $(TARGET_Q4) $(LDFLAGS)


data_process.so: $(MODULE_DIR)/data_process.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GOFLAGS) -c -fPIC $(MODULE_DIR)/data_process.c -o $(BUILD_DIR)/data_process.o
	$(CC) $(DYNFLAGS) $(BUILD_DIR)/data_process.o -o $(DYNAMIC_LIB)
	rm -f $(BUILD_DIR)/data_process.o

build_with_dynamic: data_process.so $(SRCS_Q5)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GOFLAGS) -g $(SRCS_Q5) -L$(BUILD_DIR) -ldata_process -o $(TARGET_Q5) -Wl,-rpath,'$$ORIGIN' $(LDFLAGS)


clean:
	rm -rf $(BUILD_DIR)/*

rebuild: clean all

.PHONY: all clean rebuild data_stat.a build_with_static data_process.so build_with_dynamic
