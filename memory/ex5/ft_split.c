/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/16 11:04:27 by username         #+#    #+#              */
/*   Updated: 2026/07/22 13:28:22 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
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

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && !is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*copy_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**newtab;

	int (start) = 0;
	int (i) = 0;
	int (j) = 0;
	newtab = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (!newtab)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
		{
			i++;
			start = i;
		}
		while (str[i] != '\0' && !is_separator(str[i], charset))
			i++;
		if (i > start)
		{
			newtab[j] = copy_word(str, start, i);
			j++;
		}
	}
	newtab[j] = NULL;
	return (newtab);
}

/*# include <stdio.h>

int	main(void)
{
char	*str = "par pitie fonctionne ";
char	*charset = " *";
char	**newtab = ft_split(str, charset);
int		i = 0;

while (newtab[i] != NULL)
{
printf("%s\n", newtab[i]);
free(newtab[i]);
i++;
}
free(newtab);
return (0);
}*/
