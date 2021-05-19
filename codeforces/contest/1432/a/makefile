CXX = kotlinc
CXXFLAGS = -include-runtime
DEBUGFLAGS = ""
DEBUG = true
ifeq ($(DEBUG),true)
	CXXFLAGS += $(DEBUGFLAGS)
endif

TARGET := a
EXECUTE := ./$(TARGET).jar
CLEAN_TARGETS := $(TARGET)

CASES := $(sort $(basename $(wildcard *.in)))
TESTS := $(sort $(basename $(wildcard *.out)))

all: $(TARGET)

clean:
	-rm -rf $(CLEAN_TARGETS) *.res

%: %.kt
	$(LINK.kt) $< $(LOADLIBES) $(LDLIBS) -d $@

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

run: $(TARGET)
	\time $(EXECUTE)

%.res: $(TARGET) %.in
	\time $(EXECUTE) < $*.in > $*.res
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif

%.out: % # Cancel the builtin rule

__test_%: %.res %.out
	diff $*.res $*.out

runs: $(patsubst %,%.res,$(CASES))

solve: runs

test: $(patsubst %,__test_%,$(TESTS))

.PHONY: all clean run test __test_% runs solve

.PRECIOUS: %.res
