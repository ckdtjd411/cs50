#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    if (list == NULL)
        return 1;
    
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
        return 1;
    
    list = tmp;
    tmp[3] = 4;

    
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", list[i]);
    }
    free(list);
}
