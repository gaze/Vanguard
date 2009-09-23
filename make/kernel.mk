include make/compile.mk

$(BUILD_DIR)/$(KERNEL) : $(OBJ_IN)
	@echo kernel $@
	$(Q)$(LD) $(LDFLAGS) -T $(LINKSCRIPT) -L $(LIBGCC_PATH) -o $@ $(OBJ_IN) $(LIBGCC)
