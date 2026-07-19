/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strdup.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 11:04:36 by username         #+#    #+#              */
/*   Updated: 2026/07/16 11:04:36 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
int ft_strlen(char *src)
{
    int i = 0;
    while (src[i]!= '\0')
    {
        i++;
    }
    return (i);
    
}
char	*ft_strdup(char *src)
{
    int i = 0;
    char *new;
    int size = ft_strlen(src);
    new = malloc(size*sizeof(char));
    while (src[i]!='\0')
    {
        new[i] =src[i];
        i++;
    }
    return (new);
}

#include<stdio.h>

int    main(void)
{
    char    *src = "yo ?";
    char    *new = ft_strdup(src);
    int      i = 0;

        printf("%s", new);
        i++;
    return (0);
}