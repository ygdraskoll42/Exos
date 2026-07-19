char *ft_strjoin(int size, char **strs, char *sep)
{
    int i = 0;
    int j = 0;
    char *result; 

    result = malloc (size +1 * sizeof(char));
    while ( i < size)
    {
        while (strs[j] != '\0')
            result[]=*strs[j];
    }
}