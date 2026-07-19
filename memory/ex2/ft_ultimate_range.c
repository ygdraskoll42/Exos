#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int j = 0;
    int diff;

    diff = max - min;

    if (min >= max)
    {
        *range = NULL;
        return 0;
    }

    *range = malloc(diff * sizeof(int));
    if (*range == NULL)
        return -1;

    while (j < diff)
    {
        (*range)[j] = min + j;
        j++;
    }
    return (diff-1);
}

#include <stdio.h>

int main(void)
{
    int *range;
    int len = ft_ultimate_range(&range, 0, 20);
    printf("%d\n", len);
    return 0;
}