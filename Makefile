#目标：分目录存放文件，用makefile编译
#.c -> SRC
#.o -> obj
#test当前目录 bin
# 边写边调
SRCDIR = ./src
OBJDIR = $(shell pwd)/obj
INCDIR = $(shell pwd)/include
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC)))
CFLAGS = -c -Wall -I $(INCDIR) 
CC = gcc

#传递给子目录makefile中的变量
export CFLAGS OBJDIR OBJ CC
all:ECHO test
	#echo $(SRC)
	#echo $(OBJDIR)
	#echo $(OBJ)
ECHO:
	echo "$(SRCDIR) begin......"
	make -C $(SRCDIR)
#两步编译 .c -> .o -> exe
test: 
	${CC}  $(OBJ) -o $@ 


.PHONY:clean
clean:
	${RM} $(OBJDIR)/*.o test
	
