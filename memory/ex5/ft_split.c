/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 11:04:27 by username         #+#    #+#              */
/*   Updated: 2026/07/18 17:35:39 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int    ft_separator(char c, char *charset)
{
    int    i = 0;

    while (charset[i] != '\0')
    {
        if (c == charset[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int    ft_count_words(char *str, char *charset)
{
    int    i = 0;
    int    in_word=0;
    int    c = 0;

    while (str[i] != '\0')
    {
        if ((!ft_separator(str[i], charset))&&(in_word==1))
        {
            in_word = 1;
            i++;
            c++;
        }
        else
            in_word = 0;
        i++;
    }
    return (c);
}

int    ft_word_length(char *str, char *charset)
{
    int    i = 0;
    int    nb = 0;

    while (str[i] != '\0' && !ft_separator(str[i], charset))
    {
        nb++;
        i++;
    }
    return (nb - 1);
}

char    **ft_split(char *str, char *charset)
{
    int        nb_word = ft_count_words(str, charset);
    int        word_length = ft_word_length(str, charset);
    int        i = 0;
    int        j = 0;
    int        k = 0;
    char    **newtab;

    newtab = malloc((nb_word + 1) * sizeof(char *));
    if (!newtab) return NULL;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && ft_separator(str[i], charset))
        {
            i++;
        }
        newtab[j] = malloc((word_length + 1) * sizeof(char));
        if (!newtab) return NULL;
        while (k < word_length)
        {
            newtab[j][k] = str[i + k];
            k++;
        }
        j++;
        i = word_length +i;
        //if (k == word_length)
          //  *newtab[k]='\0';
    }
    
    newtab[k] = NULL;
    return (newtab);
}

#include<stdio.h>

int    main(void)
{
    char    *str = "yo ?";
    char    *charset = " ";
    char    **newtab = ft_split(str, charset);
    int        i = 0;

    while (newtab[i] != NULL)
    {
        printf("%s\n", newtab[i]);
        i++;
    }
    free (newtab);
    return (0);
}