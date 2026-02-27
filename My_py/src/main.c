#include <stdio.h>
#include <assert.h>
#include "parser.h"
#include "token.h"

int main(int argc, char** argv) {
    FILE* input_file = fopen("expression.txt", "r");
    assert(input_file);

    Token* tokens = parser(input_file);
    fclose(input_file);

    for (int i = 0; i < 2; ++i) {
        printf("token_%d; kind = %d;\n")
    }

}