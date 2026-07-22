/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/21 18:04:18 by username         #+#    #+#              */
/*   Updated: 2026/07/22 13:32:39 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		if (i < size - 1)
		{
			len = len + ft_strlen(sep);
		}
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	int (i) = 0;
	int (j) = 0;
	int (k) = 0;
	if (size <= 0)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (ft_total_len(size, strs, sep) + 1));
	while (i < size)
	{
		while (strs[i][j])
			result[k++] = strs[i][j++];
		if (i < size - 1)
		{
			while (sep[j])
				result[k++] = sep[j++];
		}
		i++;
	}
	result[k] = '\0';
	return (result);
}
/*#include <stdio.h>
int    main(void)
{
char    *strs[3];
char    *sep;
sep = "/" ;
strs[0]="Salut";
strs[1]="ca va";
strs[2]="?";
printf("%s\n", ft_strjoin(3, strs, sep));
return (0);
}*/
