/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:45:46 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 10:37:42 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	get_len_base(char *base);

static int	size_number(int nb, int len_base)
{
	int	size;

	size = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > len_base)
	{
		nb = nb / len_base;
		++size;
	}
	++size;
	return (size);
}

static int	set_string(char **itoa, int len_number, int *nb)
{
	if (*nb < 0)
	{
		*itoa = (char *)malloc(len_number * sizeof(char));
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

char	*ft_itoa_base(int nb, char *base)
{
	const int	len_base = get_len_base(base);
	const int	len_number = size_number(nb, len_base);
	char		*itoa;
	int			i;

	if (len_base > 1)
	{
		i = set_string(&itoa, len_number, &nb);
		while (nb > len_base)
		{
			itoa[i] = base[nb % len_base];
			nb = nb / len_base;
			++i;
		}
		itoa[i] = base[nb];
		return (itoa);
	}
	return (NULL);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;

	nb = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nb, base_to));
}
/*
#include <stdio.h>

int	main()
{
	char *str;
	str = ft_convert_base("-65", "0123456789", "01");
	printf("%s", str);
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
