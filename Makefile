# Ad Maiorem Dei Gloriam!

# Compiler
CC = gcc
DEBUGGER = valgrind

# Output
OUT = bin/Todo

# Inputs
IN = src/tasks.c src/CLI.c src/main.c

# Include Directories
PROJECTINCLUDES = -Iinclude

# Warnings
WARNS = # -Wall -Wextra -Werror

# Tags
all: prepareDirectories
	${CC} ${IN} -o ${OUT} ${WARNS} ${PROJECTINCLUDES}

debug: prepareDirectories
	${CC} -g ${IN} -o ${OUT} ${PROJECTINCLUDES}
	${DEBUGGER} ${OUT} --track-origins=yes

prepareDirectories:
	mkdir -p bin
