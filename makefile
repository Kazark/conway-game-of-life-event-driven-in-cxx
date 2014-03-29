UNAME := $(shell uname -m)
GTEST_DIR = $(HOME)/dev/gtest-1.6.0/
GTEST_ARCHIVE = lib/$(UNAME)/gtest_main.a

OBJ_DIR = obj
BIN_DIR = bin
PROJECT_NAME = GameOfLife

PRODUCTION_SRC = $(wildcard src/*.cpp)
UNIT_TEST_SRC = $(wildcard unittest/*.cpp)
INTEGRATION_TEST_SRC = $(wildcard integrationtest/*.cpp)

PRODUCTION_OBJ = $(subst src/,$(OBJ_DIR)/,$(subst .cpp,.o,$(PRODUCTION_SRC)))
UNIT_TEST_OBJ = $(subst unittest/,$(OBJ_DIR)/unittest/,$(subst .cpp,.o,$(UNIT_TEST_SRC)))
INTEGRATION_TEST_OBJ = $(subst integrationtest/,$(OBJ_DIR)/integrationtest/,$(subst .cpp,.o,$(INTEGRATION_TEST_SRC)))

PRODUCTION_BINARY = $(BIN_DIR)/$(PROJECT_NAME)
UNIT_TEST_BINARY = $(BIN_DIR)/unittest_$(PROJECT_NAME)
INTEGRATION_TEST_BINARY = $(BIN_DIR)/integrationtest_$(PROJECT_NAME)

# Flags passed to the preprocessor.
CPPFLAGS = -Iinc
CPPFLAGS_TEST += $(CPPFLAGS) \
                 -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -std=c++0x

all: ut
	
ut: $(BIN_DIR) $(UNIT_TEST_BINARY) run_unit_tests 

it: $(BIN_DIR) $(INTEGRATION_TEST_BINARY) run_integration_tests

build: $(BIN_DIR) $(PRODUCTION_BINARY)

$(PRODUCTION_BINARY): $(PRODUCTION_OBJ) $(OBJ_DIR)/main/main.o
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -o $(PRODUCTION_BINARY)

$(UNIT_TEST_BINARY): $(PRODUCTION_OBJ) $(UNIT_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

$(INTEGRATION_TEST_BINARY): $(PRODUCTION_OBJ) $(INTEGRATION_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

$(OBJ_DIR)/%.o: src/%.cpp $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/unittest/%.o: unittest/%.cpp $(OBJ_DIR)/unittest
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/integrationtest/%.o: integrationtest/%.cpp $(OBJ_DIR)/integrationtest
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR) $(OBJ_DIR)/unittest $(OBJ_DIR)/integrationtest $(OBJ_DIR)/main:
	mkdir -p $@

$(OBJ_DIR)/main/main.o: main.cpp $(OBJ_DIR)/main
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: debugunit
debugunit:
	gdb $(UNIT_TEST_BINARY)

.PHONY: memcheck
memcheck:
	valgrind $(UNIT_TEST_BINARY)

.PHONY: run_unit_tests
run_unit_tests:
	$(UNIT_TEST_BINARY)

.PHONY: run_integration_tests
run_integration_tests:
	$(INTEGRATION_TEST_BINARY)

.PHONY: exec
exec:
	$(PRODUCTION_BINARY)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)/ $(BIN_DIR)/*$(PROJECT_NAME)

.PHONY: help
help:
	@$(MAKE) --print-data-base --question no-such-target 2>&1 | \
	grep -v -e '^no-such-target' -e '^makefile' | \
	awk '/^[^.%][-A-Za-z0-9_]*:/ { print substr($$1, 1, length($$1)-1) }' | \
	sed '/^bin$$/d' | sed '/^obj$$/d' | \
	sort | \
	pr --omit-pagination --width=80 --columns=4
