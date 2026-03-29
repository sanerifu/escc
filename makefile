rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

SOURCES := $(call rwildcard,./,*.cpp)
OUTPUT := main

CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Werror -g3 -fsanitize=leak -fsanitize=address
LDFLAGS :=

.PHONY: run
run: $(OUTPUT)
	@echo RUNNING
	@./$(OUTPUT)

$(OUTPUT): $(SOURCES)
	@echo COMPILING
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $(OUTPUT)
