# Shell
SHELL = /bin/bash

# Usa automaticamente tutti i core disponibili per la compilazione parallela
MAKEFLAGS += -j$(shell nproc)

# Compilatore
CXX = g++

# Flag comuni
CXXFLAGS_COMMON = -Wall -Wextra -Wpedantic -Wshadow -Wnull-dereference -std=c++17

# Flag per versione release (ottimizzata)
CXXFLAGS_RELEASE = $(CXXFLAGS_COMMON) -O3 -march=native -DNDEBUG

# Flag per versione debug (con gprof e sanitizer)
CXXFLAGS_DEBUG = $(CXXFLAGS_COMMON) -g -O0 -pg -fsanitize=address -fsanitize=undefined

# Flag di default (release)
CXXFLAGS = $(CXXFLAGS_RELEASE)

# Nome eseguibile
TARGET = blackjack
TARGET_DEBUG = blackjack_debug

# Trova automaticamente tutte le directory che contengono file .cpp
SRCDIRS = $(shell find . -type f -name "*.cpp" -exec dirname {} \; | sort -u)

# Trova automaticamente tutti i file .cpp
SOURCES = $(shell find . -type f -name "*.cpp")

# Genera automaticamente i nomi dei file .o dai file .cpp
OBJS = $(SOURCES:.cpp=.o)
OBJS_DEBUG = $(SOURCES:.cpp=_debug.o)

# Target default: compila versione release
all: $(TARGET)

# Target debug: compila versione debug con gprof e sanitizer
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(TARGET_DEBUG)

# Linking versione release
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS_RELEASE) -o $@ $^

# Linking versione debug
$(TARGET_DEBUG): $(OBJS_DEBUG)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^

# Pattern rule per file .o release
%.o: %.cpp
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

# Pattern rule per file .o debug
%_debug.o: %.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Target cls: pulisce i file compilati
cls:
	rm -f $(TARGET) $(TARGET_DEBUG) $(OBJS) $(OBJS_DEBUG) gmon.out

# Target non-file
.PHONY: all debug cls
