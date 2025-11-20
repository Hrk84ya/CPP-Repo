CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
DEBUG_FLAGS = -g -DDEBUG

# Directories
BASICS_DIR = basics
OOP_DIR = oop
ALGORITHMS_DIR = algorithms
DATA_STRUCTURES_DIR = data-structures
MODERN_CPP_DIR = modern-cpp
STL_DIR = stl
TEMPLATES_DIR = templates
EXCEPTIONS_DIR = exceptions
MULTITHREADING_DIR = multithreading
TESTS_DIR = tests

# Build all examples
all: basics oop algorithms data-structures modern-cpp stl templates exceptions multithreading

basics:
	@echo "Building basics examples..."
	@for file in $(BASICS_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

oop:
	@echo "Building OOP examples..."
	@for file in $(OOP_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

algorithms:
	@echo "Building algorithms examples..."
	@for file in $(ALGORITHMS_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

data-structures:
	@echo "Building data structures examples..."
	@for file in $(DATA_STRUCTURES_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

modern-cpp:
	@echo "Building modern C++ examples..."
	@for file in $(MODERN_CPP_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

stl:
	@echo "Building STL examples..."
	@for file in $(STL_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

templates:
	@echo "Building templates examples..."
	@for file in $(TEMPLATES_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

exceptions:
	@echo "Building exceptions examples..."
	@for file in $(EXCEPTIONS_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -o "$${file%.cpp}"; \
		fi \
	done

multithreading:
	@echo "Building multithreading examples..."
	@for file in $(MULTITHREADING_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -pthread -o "$${file%.cpp}"; \
		fi \
	done

tests:
	@echo "Building tests..."
	@for file in $(TESTS_DIR)/*.cpp; do \
		if [ -f "$$file" ]; then \
			$(CXX) $(CXXFLAGS) "$$file" -lgtest -lgtest_main -pthread -o "$${file%.cpp}"; \
		fi \
	done

debug:
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(FILE) -o $(basename $(FILE))

clean:
	@echo "Cleaning executables..."
	@find . -type f -executable -not -path "./.git/*" -delete
	@echo "Clean complete."

.PHONY: all basics oop algorithms data-structures modern-cpp stl templates exceptions multithreading tests debug clean