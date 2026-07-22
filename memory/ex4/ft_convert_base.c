/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_convert_base.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/07/21 15:28:35 by username         #+#    #+#              */
/*   Updated: 2026/07/22 13:28:13 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	is_in_base(char c, char *base);
int	index_in_base(char c, char *base);

int	is_valide_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	if (base[0] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	nb;
	int	base_len;

	i = 0;
	sign = 1;
	nb = 0;
	base_len = ft_strlen(base);
	while (str[i] <= 32)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (is_in_base(str[i], base))
	{
		nb = nb * base_len + index_in_base(str[i], base);
		i++;
	}
	return (nb * sign);
}

int	count_digit(int nb, int base_len)
{
	int	count;

	count = 1;
	if (nb < 0)
		nb = -nb;
	while (nb >= base_len)
	{
		nb = nb / base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(int nb, char *base)
{
	char	*str;
	int		base_len;
	int		len;
	int		n;

	base_len = ft_strlen(base);
	len = count_digit(nb, base_len);
	if (nb < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	n = nb;
	if (n < 0)
		n = -n;
	while (len > 0)
	{
		len--;
		str[len] = base[n % base_len];
		n = n / base_len;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char
	*base_to)
{
	int	nb;

	if (!is_valide_base(base_from) || !is_valide_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}
/*#include <stdio.h>
int main ()
{
int resultat= ft_convert_base("12","","0123456789");
if (resultat == NULL)
{
printf("erreur")
return (0);
}
printf("%s\n",resultat);
return (0);
}*/
