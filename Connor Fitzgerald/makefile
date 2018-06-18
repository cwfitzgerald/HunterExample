##############
### CONFIG ###
##############
SOCIAL_1    := social.cpp
SOCIAL_2    := social2.cpp
SOCIAL_3    := social3.cpp
SOCIAL_4    := social4.cpp
SOCIAL_IMPL := social_impl.cpp # Optional


######################
### IMPLEMENTATION ###
######################


# Various settings and paths

WARNINGS := -fdiagnostics-color=always -Wall -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wdisabled-optimization -Wdouble-promotion -Wextra -Wformat=2 -Winit-self -Wlogical-op -Wno-gnu-zero-variadic-macro-arguments -Wmissing-include-dirs -Wno-sign-conversion -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wredundant-decls -Wshadow -Wstrict-aliasing=1 -Wstrict-null-sentinel -Wstrict-overflow=1 -Wswitch-default -Wundef -Wno-unknown-pragmas -Wuseless-cast -Wno-unknown-warning-option
STANDARD := -std=c++14 $(CXXFLAGS)
DEPENDS   = -MMD -MF $(patsubst %.cpp,depends/%.d,$<)


# Functions for auto generation of object file names

CPP_OBJ = $(foreach f,$(1),$(patsubst %.cpp,obj/%.o,$(f)))


# Debug modes are helpful

ifdef DEBUG
CPP_OPTIMIZATION := -O0 -g -DDEBUG -fsanitize=address,undefined
else
CPP_OPTIMIZATION := -O3 -DNDEBUG
endif


# Pull in header dependencies
-include $(wildcard depends/*.d)


# Global target definitions
.DEFAULT_GOAL := all
.PHONY: all clean run-tests
ALL_TARGETS = taska taskb taskc taskd
all: $(ALL_TARGETS)

run-tests: all
	./taska
	./taskb
	./taskc
	./taskd


# Temp folders

obj depends:
	@echo 'Creating Directory $@'
	@mkdir -p $@


# Information for the social target

SOCIAL_CPP_OBJ := $(call CPP_OBJ, $(SOCIAL_1) $(SOCIAL_IMPL))

taska: $(SOCIAL_CPP_OBJ)
	@echo 'Linking $@'
	@$(CXX) $(WARNINGS) $(STANDARD) $(CPP_OPTIMIZATION) $(CPP_DEBUG_FLAGS) -o $@ $^


# Information for the social target

SOCIAL2_CPP_OBJ := $(call CPP_OBJ, $(SOCIAL_2) $(SOCIAL_IMPL))

taskb: $(SOCIAL2_CPP_OBJ)
	@echo 'Linking $@'
	@$(CXX) $(WARNINGS) $(STANDARD) $(CPP_OPTIMIZATION) $(CPP_DEBUG_FLAGS) -o $@ $^


# Information for the social target

SOCIAL3_CPP_OBJ := $(call CPP_OBJ, $(SOCIAL_3) $(SOCIAL_IMPL))

taskc: $(SOCIAL3_CPP_OBJ)
	@echo 'Linking $@'
	@$(CXX) $(WARNINGS) $(STANDARD) $(CPP_OPTIMIZATION) $(CPP_DEBUG_FLAGS) -o $@ $^


# Information for the social target

SOCIAL4_CPP_OBJ := $(call CPP_OBJ, $(SOCIAL_4) $(SOCIAL_IMPL))

taskd: $(SOCIAL4_CPP_OBJ)
	@echo 'Linking $@'
	@$(CXX) $(WARNINGS) $(STANDARD) $(CPP_OPTIMIZATION) $(CPP_DEBUG_FLAGS) -o $@ $^


# Generic catchall targets for building C++ and ISPC

# C++
obj/%.o: %.cpp | obj depends 
	@echo 'Building CXX Object $< -> $@'
	@$(CXX) $(WARNINGS) $(STANDARD) $(CPP_OPTIMIZATION) $(CPP_DEBUG_FLAGS) $(DEPENDS) $< -c -o $@


# Cleanup

clean:
	rm -rf obj depends
	rm -f $(ALL_TARGETS)
