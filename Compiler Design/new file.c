#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEXEME_LENGTH 100
const char *built_in_functions[] = {"printf","scanf","return","short","extern","auto",
"struct","register","continue" ,"break" ,"char" ,
 "int","double","String","long","case","static","void","typedef","volatile","union",
 "do","while","break","for","float","else"};
const int built_in_count = sizeof(built_in_functions) / sizeof(built_in_functions[0]);
int main()
{
    FILE *file;
    char input[1000];
    char lexeme[MAX_LEXEME_LENGTH];
    int i = 0, j = 0;
    file = fopen("jim.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fgets(input, sizeof(input), file))
    {
        i = 0;
        while (input[i] != '\0')
        {
            if (isspace(input[i]))
            {
                i++;
                continue;
            }
            if (isalpha(input[i]) || input[i] == '_')
            {
                j = 0;
                while (isalnum(input[i]) || input[i] == '_')
                {
                    lexeme[j++] = input[i++];
                }
                lexeme[j] = '\0';
                int is_builtin = 0;
                for (int k = 0; k < built_in_count; k++)
                {
                    if (strcmp(lexeme, built_in_functions[k]) == 0)
                    {
                        is_builtin = 1;
                        break;
                    }
                }
                if (is_builtin)
                {
                    printf("Lexeme: %-10s Token: Keyword\n", lexeme);
                }
                else
                {
                    printf("Lexeme: %-10s Token: identifier\n", lexeme);
                }
            }
            else if (isdigit(input[i]))
            {
                j = 0;
                while (isdigit(input[i]))
                {
                    lexeme[j++] = input[i++];
                }
                lexeme[j] = '\0';
                printf("Lexeme: %-10s Token: integer literal\n", lexeme);
            }
            else if (input[i] == '=')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: assignment operator\n", lexeme);
            }
            else if (input[i] == '+')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: addition operator\n", lexeme);
            }
            else if (input[i] == '-')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: substraction operator\n", lexeme);
            }
            else if (input[i] == '*')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: multification operator\n", lexeme);
            }
            else if (input[i] == '/')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: Divisor operator\n", lexeme);
            }
            else if (input[i] == ';')
            {
                lexeme[0] = input[i++];
                lexeme[1] = '\0';
                printf("Lexeme: %-10s Token: end of statement\n", lexeme);
            }
            else
            {
                i++;
            }
        }
    }
    fclose(file);
    return 0;
}
