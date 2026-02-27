#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "include/token.h"

// Функция для проверки, является ли строка числом
int is_number(const char *str) {
    if (str == NULL || *str == '\0') return 0;
    
    char *endptr;
    strtol(str, &endptr, 10);
    return *endptr == '\0';
}

// Функция для проверки, является ли символ бинарным оператором
int is_binary_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || 
            c == '%' || c == '=' || c == '<' || c == '>' || 
            c == '&' || c == '|' || c == '^');
}

// Функция для освобождения памяти, выделенной под токены
void free_tokens(Token *tokens) {
    if (!tokens) return;
    
    for (int i = 0; tokens[i].value.string_value != NULL; i++) {
        // Освобождаем строки только для VAR токенов
        if (tokens[i].kind == VAR && tokens[i].value.string_value != NULL) {
            free(tokens[i].value.string_value);
        }
    }
    free(tokens);
}

Token* parser(FILE* file) {
    if (!file) return NULL;
    
    // Читаем первую строку из файла
    char buffer[1024];
    if (!fgets(buffer, sizeof(buffer), file)) {
        return NULL;
    }
    
    // Убираем символ новой строки
    buffer[strcspn(buffer, "\n")] = 0;
    
    // Создаем копию строки для strtok
    char *line_copy = strdup(buffer);
    if (!line_copy) return NULL;
    
    // Первый проход: подсчитываем количество токенов
    int token_count = 0;
    char *temp_line = strdup(buffer);
    char *saveptr1;
    
    char *token = strtok_r(temp_line, " \t", &saveptr1);
    while (token != NULL) {
        token_count++;
        token = strtok_r(NULL, " \t", &saveptr1);
    }
    free(temp_line);
    
    if (token_count == 0) {
        free(line_copy);
        return NULL;
    }
    
    // Выделяем память под массив токенов ( +1 для NULL-терминатора)
    Token *tokens = (Token*)malloc((token_count + 1) * sizeof(Token));
    if (!tokens) {
        free(line_copy);
        return NULL;
    }
    
    // Второй проход: заполняем токены
    int index = 0;
    char *saveptr2;
    token = strtok_r(line_copy, " \t", &saveptr2);
    
    while (token != NULL && index < token_count) {
        // Проверяем, является ли токен числом
        if (is_number(token)) {
            tokens[index].kind = NUM;
            tokens[index].value.int_value = atoi(token);
        }
        // Проверяем, является ли токен бинарным оператором
        else if (strlen(token) == 1 && is_binary_operator(token[0])) {
            tokens[index].kind = BIN_OP;
            tokens[index].value.char_value = token[0];
        }
        // Иначе считаем это переменной/идентификатором
        else {
            tokens[index].kind = VAR;
            tokens[index].value.string_value = strdup(token);
        }
        
        index++;
        token = strtok_r(NULL, " \t", &saveptr2);
    }
    
    // Добавляем NULL-терминатор для удобства
    tokens[index].kind = VAR;  // Значение не важно, главное что string_value == NULL
    tokens[index].value.string_value = NULL;
    
    free(line_copy);
    return tokens;
}

// Пример использования
int main() {
    FILE *file = fopen("expression.txt", "r");
    if (!file) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    
    Token *tokens = parser(file);
    fclose(file);
    
    if (tokens) {
        printf("Полученные токены:\n");
        for (int i = 0; tokens[i].value.string_value != NULL; i++) {
            printf("Токен %d: ", i);
            
            switch (tokens[i].kind) {
                case NUM:
                    printf("NUM (число): %d\n", tokens[i].value.int_value);
                    break;
                    
                case VAR:
                    printf("VAR (переменная): %s\n", tokens[i].value.string_value);
                    break;
                    
                case BIN_OP:
                    printf("BIN_OP (оператор): %c\n", tokens[i].value.char_value);
                    break;
                    
                default:
                    printf("Неизвестный тип токена\n");
            }
        }
        
        free_tokens(tokens);
    } else {
        printf("Не удалось распарсить файл\n");
    }
    
    return 0;
}