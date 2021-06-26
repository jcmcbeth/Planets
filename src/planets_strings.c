#include <ctype.h>
#include <string.h>

#include "planets_strings.h"

void replace_char(char* buffer, char replace, char with)
{
    size_t i = 0;

    for (i = 0; i < strlen(buffer); ++i)
    {
        if (buffer[i] == replace)
        {
            buffer[i] = with;
        }
    }
}