/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_ultimate_range.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/21 12:39:11 by username         #+#    #+#              */
/*   Updated: 2026/07/22 13:28:01 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	j;
	int	diff;

	j = 0;
	diff = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(diff * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (j < diff)
	{
		(*range)[j] = min + j;
		j++;
	}
	return (diff - 1);
}

/*#include <stdio.h>

int	main(void)
{
int	*range;
int	len = ft_ultimate_range(&range, 0, 20);

printf("%d\n", len);
return (0);
}*/
