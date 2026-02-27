#ifndef INCLUDE_TOKEN_H
#define INCLUDE_TOKEN_H

typedef enum token_kind {
    NUM, VAR, BIN_OP,  
} token_kind;

typedef union value_t {
    int int_value;
    char char_value;
    char* string_value;
} value_t;

typedef struct Token {
    token_kind kind;
    value_t value;
} Token;

#endif // INCLUDE_TOKEN_H