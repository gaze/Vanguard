GET_LOCAL_DIR    = $(patsubst %/,%,$(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
MKDIR = if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi

NOECHO=@

LIBGCC_PATH := $(dir $(shell $(CC) $(GLOBAL_CFLAGS) -print-libgcc-file-name))
LIBGCC := -lgcc

INCLUDES= -I./Headers -I./Headers/archs/i386

BUILD_DIR=build

Q=@


include Projects/mk

clean:
	rm -rf $(BUILD_DIR)
