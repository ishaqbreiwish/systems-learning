#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char input[1024];

    while (1)
    {
        printf("db > ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, ".exit") == 0)
        {
            break;
        }
        else
        {
            printf("Unrecognized Command: %s", input); // prints out an error
        }
    }

    return 0;
}
