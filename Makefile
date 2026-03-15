# Ad Maiorem Dei Gloriam!

# Compiler
CC = gcc

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

prepareDirectories:
	mkdir -p bin
