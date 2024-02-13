/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:11 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 09:56:06 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric_char(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;
	int	i;

	is_numeric = 1;
	i = 0;
	while (str[i] != '\0' && is_numeric == 1)
	{
		is_numeric = is_numeric_char(str[i]);
		++i;
	}
	return (is_numeric);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_str_is_numeric(av[1]));
}
*/
