UNAME := $(shell uname -m)
GTEST_DIR = $(HOME)/dev/gtest-1.6.0/
GTEST_ARCHIVE = lib/$(UNAME)/gtest_main.a

BIN_DIR = bin
PROJECT_NAME = GameOfLife

PRODUCTION_SRC = $(wildcard src/*.cpp)
UNIT_TEST_SRC = $(wildcard unittest/*.cpp)
SYSTEM_TEST_SRC = $(wildcard systemtest/*.cpp)

PRODUCTION_OBJ = $(subst src/,obj/,$(subst .cpp,.o,$(PRODUCTION_SRC)))
UNIT_TEST_OBJ = $(subst unittest/,obj/unittest/,$(subst .cpp,.o,$(UNIT_TEST_SRC)))
SYSTEM_TEST_OBJ = $(subst systemtest/,obj/systemtest/,$(subst .cpp,.o,$(SYSTEM_TEST_SRC)))

PRODUCTION_BINARY = $(BIN_DIR)/$(PROJECT_NAME)
UNIT_TEST_BINARY = $(BIN_DIR)/unittest_$(PROJECT_NAME)
SYSTEM_TEST_BINARY = $(BIN_DIR)/systemtest_$(PROJECT_NAME)

# Flags passed to the preprocessor.
CPPFLAGS = -Iinc
CPPFLAGS_TEST += $(CPPFLAGS) \
                 -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -std=c++0x

all: $(BIN_DIR) $(UNIT_TEST_BINARY) run_unit_tests 

build: $(BIN_DIR) $(PRODUCTION_BINARY)

st: $(BIN_DIR) $(SYSTEM_TEST_BINARY) run_system_tests

$(PRODUCTION_BINARY): $(PRODUCTION_OBJ) obj/main/main.o
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -o $(PRODUCTION_BINARY)

$(UNIT_TEST_BINARY): $(PRODUCTION_OBJ) $(UNIT_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

$(SYSTEM_TEST_BINARY): $(PRODUCTION_OBJ) $(SYSTEM_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

obj/%.o: src/%.cpp obj
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

obj/unittest/%.o: unittest/%.cpp obj/unittest
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

obj/systemtest/%.o: systemtest/%.cpp obj/systemtest
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

obj obj/unittest obj/systemtest obj/main:
	mkdir -p $@

obj/main/main.o: main.cpp obj/main
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

.PHONY: run_unit_tests
run_unit_tests:
	$(UNIT_TEST_BINARY)

.PHONY: run_system_tests
run_system_tests:
	$(SYSTEM_TEST_BINARY)

.PHONY: run
run:
	$(PRODUCTION_BINARY)

.PHONY: clean
clean:
	rm -rf obj/ $(BIN_DIR)/*$(PROJECT_NAME)

