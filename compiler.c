#include <stdio.h>    // Standard input and output functions
#include <stdlib.h>   // Standard library functions, including memory allocation
#include <ctype.h>    // Character type functions (e.g., isdigit)
#include <string.h>   // String manipulation functions

// Tokenizer definitions

// Enumeration for different types of tokens
typedef enum { TOKEN_NUMBER, TOKEN_PLUS, TOKEN_MINUS, TOKEN_END } TokenType;

// Structure to represent a token, which can be a number or an operator
typedef struct {
    TokenType type;  // The type of token
    int value;       // The value of the token if it is a number
} Token;

// Function to tokenize the input string
Token *tokenize(const char *input) {
    // Allocate memory for tokens
    Token *tokens = malloc(256 * sizeof(Token));
    int pos = 0;  // Position in the tokens array

    // Loop through the input string
    while (*input) {
        if (isdigit(*input)) {
            // If the character is a digit, create a TOKEN_NUMBER token
            tokens[pos].type = TOKEN_NUMBER;
            tokens[pos].value = strtol(input, (char**)&input, 10); // Convert string to long
            pos++;
        } else if (*input == '+') {
            // If the character is '+', create a TOKEN_PLUS token
            tokens[pos].type = TOKEN_PLUS;
            input++;
            pos++;
        } else if (*input == '-') {
            // If the character is '-', create a TOKEN_MINUS token
            tokens[pos].type = TOKEN_MINUS;
            input++;
            pos++;
        } else {
            // Skip any other characters (e.g., spaces)
            input++;
        }
    }

    // Mark the end of the tokens
    tokens[pos].type = TOKEN_END;
    return tokens;
}

// Parser definitions

// Function to parse the tokens and evaluate the expression
int parse(Token *tokens, int *result) {
    int pos = 0;  // Position in the tokens array

    // The expression must start with a number
    if (tokens[pos].type != TOKEN_NUMBER) {
        return 0; // Invalid expression if it doesn't start with a number
    }

    // Initialize result with the first number
    *result = tokens[pos].value;
    pos++;

    // Loop through the tokens and evaluate the expression
    while (tokens[pos].type != TOKEN_END) {
        if (tokens[pos].type == TOKEN_PLUS) {
            // If the token is '+', add the next number to the result
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0; // Invalid expression if '+' is not followed by a number
            }
            *result += tokens[pos].value;
        } else if (tokens[pos].type == TOKEN_MINUS) {
            // If the token is '-', subtract the next number from the result
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0; // Invalid expression if '-' is not followed by a number
            }
            *result -= tokens[pos].value;
        } else {
            // Invalid token
            return 0;
        }
        pos++;
    }

    // Successful parsing and evaluation
    return 1;
}

// Code generator definitions

// Function to generate assembly-like instructions from the tokens
void generate_assembly(Token *tokens) {
    int pos = 0;  // Position in the tokens array

    // Load the first number into a register
    printf("LOAD %d\n", tokens[pos].value);
    pos++;

    // Loop through the tokens and generate instructions
    while (tokens[pos].type != TOKEN_END) {
        if (tokens[pos].type == TOKEN_PLUS) {
            // If the token is '+', generate an ADD instruction
            pos++;
            printf("ADD %d\n", tokens[pos].value);
        } else if (tokens[pos].type == TOKEN_MINUS) {
            // If the token is '-', generate a SUB instruction
            pos++;
            printf("SUB %d\n", tokens[pos].value);
        }
        pos++;
    }
}

// Main function

int main() {
    char input[256];  // Buffer to hold the input string

    // Prompt the user to enter an arithmetic expression
    printf("Enter an arithmetic expression (e.g., 3 + 4 - 2): ");
    fgets(input, sizeof(input), stdin);  // Read the input from the user

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Tokenize the input
    Token *tokens = tokenize(input);

    int result;
    // Parse the tokens and evaluate the expression
    if (parse(tokens, &result)) {
        // Print the parsed result
        printf("Parsed result: %d\n", result);
        // Generate assembly-like instructions
        generate_assembly(tokens);
    } else {
        // Print an error message if the expression is invalid
        printf("Invalid expression\n");
    }

    // Free the allocated memory for tokens
    free(tokens);
    return 0;
}

