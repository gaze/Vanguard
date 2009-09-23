OBJ_IN = $(addprefix $(BUILD_DIR)/, $(OBJ))

$(BUILD_DIR)/%.o: %.c
	@$(MKDIR)
	@echo compiling $<
	$(Q)$(CC) $(CFLAGS) --std=c99 $(INCLUDES) -c $< -MD -MT $@ -MF $(@:%o=%d) -o $@

$(BUILD_DIR)/%.o: %.S
	@$(MKDIR)
	@echo assembling $<
	$(Q)$(CC) $(CFLAGS) --std=c99 $(INCLUDES) -c $< -MD -MT $@ -MF $(@:%o=%d) -o $@ -D__ASM__
