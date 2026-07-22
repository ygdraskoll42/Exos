/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_range.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/21 12:38:26 by username         #+#    #+#              */
/*   Updated: 2026/07/22 13:27:57 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc((max + 1) * sizeof(int));
	while (i < max)
	{
		if (min > max)
			return (NULL);
		if (min == max)
			tab[i] = min;
		else
			tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
int	i = 0;
int	*tab = ft_range(20, 10);

while (tab[i] != 20)
{
printf("%d\n", tab[i]);
i++;
}
return (0);
}*/
