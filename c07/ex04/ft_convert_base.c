/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:45:46 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 19:09:20 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

int	ft_atoi_base(char *str, char *base, bool *is_valid_base);
int	get_len_base(char *base);

static int	size_number(long nb, int len_base)
{
	int	size;

	size = 0;
	if (nb < 0)
		nb *= -1;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		++size;
	}
	++size;
	return (size);
}

static int	set_string(char **itoa, int len_number, long *nb)
{
	if (*nb < 0)
	{
		*itoa = (char *)malloc(len_number + 1 * sizeof(char));
		if (*itoa == NULL)
			return (-1);
		*nb *= -1;
		*itoa[0] = '-';
		return (1);
	}
	else
	{
		*itoa = (char *)malloc(len_number * sizeof(char));
		return (0);
	}
}

char	*ft_itoa_base(long nb, char *base)
{
	const int	len_base = get_len_base(base);
	int			len_number;
	char		*itoa;
	int			i;
	int			i_min;

	if (len_base > 1)
	{
		len_number = size_number(nb, len_base);
		i_min = set_string(&itoa, len_number, &nb);
		i = len_number - (i_min == 0);
		while (nb >= len_base)
		{
			itoa[i] = base[nb % len_base];
			nb = nb / len_base;
			--i;
		}
		itoa[i_min] = base[nb];
		return (itoa);
	}
	return (NULL);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	bool	is_valid_base;

	nb = ft_atoi_base(nbr, base_from, &is_valid_base);
	if (!is_valid_base)
		return (NULL);
	return (ft_itoa_base(nb, base_to));
}
/*
#include <stdio.h>
#include <limits.h>

int	main()
{
	char	*str;
	char	*str2;
	str = ft_convert_base("0", "12", "12");
	str2 = ft_convert_base(str, "01", "0123456789ABCDEF");
	printf("%s\n", str);
	printf("%s\n", str2);
	printf("%s\n", ft_itoa_base(0, "01"));
	free(str);
}
*/
/*
	
	itoa_base
		-> but:
			-> transformer int en char * base
		args:
			-> char * base
			-> int nb
		process:
			-> trouver la len du nombre (division par len_base)
			-> copier le nombre pour le diviser par len de base puis ;odulo 
				len_base (tkt t'as capte)

	process:
		-> transformer le nombre en base 10 a partir de basefrom (atoi_base)
		-> transformer le int base 10 en base base_to (itoa_base)
		-> return nb
*/
