# Used to call makefiles in prb*/ subdirectories with either all, build, run, or clean
TOPTARGETS := all build run clean

SUBDIRS := $(wildcard prb*/.)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)