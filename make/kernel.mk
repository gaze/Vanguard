include make/compile.mk

$(BUILD_DIR)/$(KERNEL) : $(OBJ_IN)
	@echo kernel $@
	@$(LD) $(LDFLAGS) -T $(LINKSCRIPT) -L $(LIBGCC_PATH) -o $@ $(OBJ_IN) $(LIBGCC)
