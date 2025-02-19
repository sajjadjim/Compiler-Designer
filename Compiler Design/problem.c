#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *file;
    char input[1000];
    char lexeme[100];
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
            if (input[i] == ' ')
            {
                i++;
                continue;
            }
            if (isalpha(input[i]))
            {
                j = 0;
                while (isalnum(input[i]) || input[i] == '_')
                {
                    lexeme[j++] = input[i++];
                }
                lexeme[j] = '\0';
                printf("Lexeme: %-10s Token: identifier\n", lexeme);
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
