#all:
#	echo "+++++"
#fun.o:fun.c
#	echo $(CFLAGS)
#	gcc $(CFLAGS) $< -o $@
all:$(OBJ)
$(OBJDIR)/%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
