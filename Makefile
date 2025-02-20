TARGET = main
COMPILER = gcc

PREF_SRC = ./src/
PREF_OBJ = ./obj/
SRC = ${wildcard $(PREF_SRC)*.c}
OBJ = ${patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, ${SRC}}

${TARGET} : ${OBJ}
	${COMPILER} ${OBJ} -o ${TARGET}

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	$(COMPILER) -c $< -o $@

clean :
	rm -rf $(TARGET) $(PREF_OBJ)*.o