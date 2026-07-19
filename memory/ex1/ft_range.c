#include<stdlib.h>
int *ft_range(int min, int max)
{
    int i=0;
    int *tab;
    tab = malloc((max+1)*sizeof(int));

    while (i < max)
    {
        if (min > max)
            return NULL;
        if (min == max)
            tab[i]=min;
        else
        tab[i]= min + i;
        i++;
    }
    return (tab);
}

#include<stdio.h>

int    main(void)
{
    int        i = 0;
    int *tab = ft_range(10,20);


    while (tab[i] != 20)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}