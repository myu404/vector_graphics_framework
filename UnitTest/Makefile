DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS=-g
else
   OPTFLAGS=-O3
endif

CFLAGS=-I. -I../VectorGraphics -I../CppUnitLite -Wall -Werror $(OPTFLAGS)
CPPFLAGS=-std=c++20

PROJDIR := $(realpath $(CURDIR)/..)
BUILDDIR := $(PROJDIR)/Output

DIRS = UnitTest

SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(PROJDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir))) ../bin
VPATH = $(SOURCEDIRS)
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

OBJ := $(subst $(PROJDIR),$(BUILDDIR), $(SOURCES:.cpp=.o))

define generateRules
$(1)/%.o: %.cpp
	$$(CXX) -c -o $$@ $$< $$(CFLAGS) $$(CPPFLAGS)
endef

UnitTest: $(OBJ) directories VectorGraphics CppUnitLite
	$(CXX) -L../VectorGraphics -L../CppUnitLite $(OBJ) -o ../bin/UnitTest -lVectorGraphics -lCppUnitLite $(OPTFLAGS)

VectorGraphics:
	$(MAKE) -j -C ../VectorGraphics all

CppUnitLite:
	$(MAKE) -j -C ../CppUnitLite all

$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	mkdir -p $(TARGETDIRS)

all: directories VectorGraphics CppUnitLite UnitTest

clean:
	$(MAKE) -j -C ../VectorGraphics clean
	$(MAKE) -j -C ../CppUnitLite clean
	rm -rf $(TARGETDIRS)
	rm -rf $(BUILDDIR)
