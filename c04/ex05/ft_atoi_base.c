/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:55:35 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/19 20:00:39 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#define SPACE 32
#define FIRST_WHITESPACE 9
#define LAST_WHITESPACE 13

static void	fill_tab(bool *ascii_verif)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		if (i == '+' || i == '-' || (i < 32 && i > 126))
			ascii_verif[i] = true;
		else
			ascii_verif[i] = false;
		++i;
	}
}

static int	get_len_base(char *base)
{
	bool	ascii_verif[256];
	int		i;
	int		c;

	i = 0;
	fill_tab(ascii_verif);
	while (base[i] != '\0')
	{
		c = base[i];
		if (ascii_verif[c] == false)
			ascii_verif[c] = true;
		else
			return (0);
		++i;
	}
	return (i);
}

static int	get_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

long	convert_base(char *str, char *base, int len_base, int i)
{
	long	value;

	value = 0;
	while (str[i] != '\0' && get_number(str[i], base) != -1)
	{
			value = value * len_base + get_number(str[i], base);
			++i;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		i;
	int		len_base;
	long	atoi;

	atoi = 0;
	len_base = get_len_base(base);
	if (len_base > 1)
	{
		sign = 1;
		i = 0;
		while (str[i] == SPACE
			|| (FIRST_WHITESPACE <= str[i] && str[i] <= LAST_WHITESPACE))
			++i;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			++i;
		}
		atoi = convert_base(str, base, len_base, i);
	}
	return (atoi * sign);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_atoi_base("-010101011", "01"));
}
*/
