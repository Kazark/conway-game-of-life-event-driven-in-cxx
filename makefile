UNAME := $(shell uname -m)
GTEST_DIR = $(HOME)/dev/gtest-1.6.0/
GTEST_ARCHIVE = lib/$(UNAME)/gtest_main.a

# IMPORTANT
PROJECT_NAME = GameOfLife

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
INC_DIR = inc
UNIT_TEST_DIR = unittest
INTEGRATION_TEST_DIR = integrationtest
UNIT_TEST_OBJ_DIR = $(OBJ_DIR)/$(UNIT_TEST_DIR)
INTEGRATION_TEST_OBJ_DIR = $(OBJ_DIR)/$(INTEGRATION_TEST_DIR)

# File paths for source files
PRODUCTION_SRC = $(wildcard $(SRC_DIR)/*.cpp)
UNIT_TEST_SRC = $(wildcard $(UNIT_TEST_DIR)/*.cpp)
INTEGRATION_TEST_SRC = $(wildcard $(INTEGRATION_TEST_DIR)/*.cpp)

#PRODUCTION_INC = $(wildcard $(INC_DIR)/*.hpp)
#UNIT_TEST_INC = $(wildcard $(UNIT_TEST_DIR)/*.hpp)
#INTEGRATION_TEST_INC = $(wildcard $(INTEGRATION_TEST_DIR)/*.hpp)

#PRODUCTION_FILES = $(PRODUCTION_SRC) $(PRODUCTION_INC)
#UNIT_TEST_FILES = $(UNIT_TEST_SRC) $(UNIT_TEST_INC)
#INTEGRATION_TEST_FILES = $(INTEGRATION_TEST_SRC) $(INTEGRATION_TEST_INC)

# File paths for object files
PRODUCTION_OBJ = $(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.o,$(PRODUCTION_SRC)))
UNIT_TEST_OBJ = $(subst $(UNIT_TEST_DIR)/,$(UNIT_TEST_OBJ_DIR)/,$(subst .cpp,.o,$(UNIT_TEST_SRC)))
INTEGRATION_TEST_OBJ = $(subst $(INTEGRATION_TEST_DIR)/,$(INTEGRATION_TEST_OBJ_DIR)/,$(subst .cpp,.o,$(INTEGRATION_TEST_SRC)))

# File paths for binary files
PRODUCTION_BINARY = $(BIN_DIR)/$(PROJECT_NAME)
UNIT_TEST_BINARY = $(BIN_DIR)/unittest_$(PROJECT_NAME)
INTEGRATION_TEST_BINARY = $(BIN_DIR)/$(INTEGRATION_TEST_DIR)_$(PROJECT_NAME)

# Flags passed to the preprocessor.
CPPFLAGS = -I$(INC_DIR)
CPPFLAGS_TEST += $(CPPFLAGS) \
                 -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -std=c++0x

all: ut

ut:$(UNIT_TEST_OBJ_DIR)  $(BIN_DIR) $(UNIT_TEST_BINARY) run_unit_tests 

it: $(INTEGRATION_TEST_OBJ_DIR) $(BIN_DIR) $(INTEGRATION_TEST_BINARY) run_integration_tests

build: $(OBJ_DIR) $(BIN_DIR) $(PRODUCTION_BINARY)

$(PRODUCTION_BINARY): $(PRODUCTION_OBJ) $(OBJ_DIR)/main/main.o
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -o $(PRODUCTION_BINARY)

$(UNIT_TEST_BINARY): $(PRODUCTION_OBJ) $(UNIT_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

$(INTEGRATION_TEST_BINARY): $(PRODUCTION_OBJ) $(INTEGRATION_TEST_OBJ) $(GTEST_ARCHIVE)
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) $^ -lpthread -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/$(UNIT_TEST_DIR)/%.o: $(UNIT_TEST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/$(INTEGRATION_TEST_DIR)/%.o: $(INTEGRATION_TEST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS_TEST) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR) $(OBJ_DIR)/$(UNIT_TEST_DIR) $(OBJ_DIR)/$(INTEGRATION_TEST_DIR) $(OBJ_DIR)/main:
	mkdir -p $@

$(OBJ_DIR)/main/main.o: main.cpp $(OBJ_DIR)/main
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# DEPENDENCY BUILDING
include $(OBJ_DIR)/main/main.d

$(OBJ_DIR)/main/main.d: main.cpp
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(subst .cpp,.d,$(PRODUCTION_SRC)))

$(OBJ_DIR)/%.d: $(PRODUCTION_SRC)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(subst $(UNIT_TEST_DIR)/,$(UNIT_TEST_OBJ_DIR)/,$(subst .cpp,.d,$(UNIT_TEST_SRC)))

$(UNIT_TEST_OBJ_DIR)/%.d: $(UNIT_TEST_SRC)
	$(CXX) -M $(CPPFLAGS) $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# PHONY TARGETS
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
