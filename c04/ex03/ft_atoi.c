/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:31:49 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/19 19:47:13 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#define WHITE_SPACES " \f\n\r\t\v"
#define CONVERT_ASCII 48

bool	is_space(char c)
{
	int	i;

	i = 0;
	while (WHITE_SPACES[i] != '\0')
	{
		if (c == WHITE_SPACES[i])
			return (true);
		++i;
	}
	return (false);
}

long	convert_number(char *str, size_t i)
{
	long	atoi;

	atoi = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + (str[i] - CONVERT_ASCII);
		++i;
	}
	return (atoi);
}

long	atoi_long(char	*str)
{
	int			sign;
	size_t		i;
	long		atoi;

	sign = 1;
	i = 0;
	while (is_space(str[i]))
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	atoi = convert_number(str, i);
	return (atoi * sign);
}

int	ft_atoi(char *str)
{
	return ((int)atoi_long(str));
}
/*
#include <stdio.h>

int	main()
{
	printf("-123: [%d]\n", ft_atoi("-2147483648"));
	printf("-+---889: [%d]\n", ft_atoi("-+--889"));
	printf(" \t123: [%d]\n", ft_atoi(" \t123"));
	printf(": [%d]\n", ft_atoi(""));
	printf(" ----- +123: [%d]\n", ft_atoi("   ----- +123"));
	printf(" -12+3: [%d]\n", ft_atoi(" -12+3"));
}
*/
