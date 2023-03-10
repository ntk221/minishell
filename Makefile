CC = gcc
FLAGS = -Wall -Wextra -Werror

TESTS 	= ./tests/*
SPLIT 	= ./split/split.c
EXE	  	= ./executer/*
BUILTIN = ./builtin_commands/echo/*

TARGET  = minishell

$(TARGET):
	$(CC) $(FLAGS) $(SPLIT) $(EXE) $(BUILTIN) main.c -lreadline -o $(TARGET)

rm:
	rm $(TARGET)

norm:
	norminette

split_test: $(TESTS) $(SPLIT)
	$(CC) $(TESTS) $(SPLIT) -o split_test
	./split_test
	rm split_test

PHONY: all clean test