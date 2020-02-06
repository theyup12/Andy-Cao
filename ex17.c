#include <stdio.h>

#define MAXLEN 1000
#define MINLEN 80

int main()
{
    int c;
    int index = 0;
    char line[MAXLEN];

    while ((c = getchar()) != EOF)
    {
        if (c != '\n')
        {
            line[index] = c;
            ++index;
        }

        else
        {
            line[index] = '\0';

            if (index >= MINLEN)
            {
                printf("%s\n", line);
            }
            index = 0;
        }
    }
    return 0;
}
