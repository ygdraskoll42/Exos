int ft_separator(char c, char *charset)
{
    int i=0;
    while (charset[i]!= '\0')
    {
        if (c == charset[i])
        {
            return(1);
        }
        else
        {
            return(0);
            i++;
        }
    }
    return 0;
}

int ft_count_words(char *str,char *charset)
{
    int i = 0;
    int c = 0;
    while (str[i]!=0)
    {

        while((!ft_separator(str[i],charset)) && ((ft_separator(str[i-1],charset) || i==0)))
        {
            while (!ft_separator(str[i],charset))
                i++;
            
        }
        if (!ft_separator(str[i+1],charset))
            c++;
        i++;
        //ft_count_words(str,charset);
        
    }
    
    return (c);
}
int ft_word_length(char *str,char *charset)
{
    int i=0;
    int nb=0;
    
    while (str[i]!=0)
    {
        if (!ft_separator(str[i],charset)&&(ft_separator(str[i],charset) ||i==0 ))
        {
            nb = 1;
        }
        i++;
        nb++;
        if (ft_separator(str[i],charset) || str[i]=='\0')
        {
            return (nb-1);
        }
    }
    return 0;
}
#include<stdio.h>
int main ()
{
    char *str = "saluddddt ca va ?  re        rr r f     ";
    char *charset =" ";
    printf("%d\n%d\n%d\n%d",ft_count_words(str,charset),ft_word_length(str,charset));
    return 0;
}