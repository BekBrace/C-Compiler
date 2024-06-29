# Arithmetic Expression Parser and Code Generator

This program demonstrates a simple arithmetic expression parser and code generator written in C. It takes an arithmetic expression from the user, parses it into tokens (numbers and operators), evaluates the expression, and optionally generates assembly-like instructions based on the parsed tokens.

## Features

- **Tokenization**: Converts an arithmetic expression into tokens (numbers and operators).
- **Parsing**: Validates and evaluates the arithmetic expression based on the parsed tokens.
- **Code Generation**: Generates assembly-like instructions for the arithmetic operations.

## Dependencies

This program relies on standard C libraries:
- `<stdio.h>`: For standard input and output functions.
- `<stdlib.h>`: For memory allocation and other standard functions.
- `<ctype.h>`: For character type functions (`isdigit`).
- `<string.h>`: For string manipulation functions.

## How to Use

1. **Compile**: Compile the program using a C compiler. For example, using GCC:

```bash
   gcc -o arithmetic_parser arithmetic_parser.c
```

2. Run: Execute the compiled program:

```bash
./arithmetic_parser
Input: Enter an arithmetic expression when prompted (e.g., 3 + 4 - 2).
```
# Feel free to fork and submit your commits, to check and approve eventually.
