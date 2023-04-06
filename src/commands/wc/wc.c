#include "wc.h"

int wc(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        char buff[100];
        sprintf(buff, "Problèmes rencontrés lors de l'ouverture du fichier %s", filename);
        perror(buff);
    }

    size_t words = 0;
    bool reading_word = false;
    char c;

    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            reading_word = true;
        }
        else if (reading_word)
        {
            ++words;
            reading_word = false;
        }
    }

    fclose(file);

    return words + reading_word;
}