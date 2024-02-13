/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:11 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 10:48:45 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper_char(char c)
{
	return ((c >= 'A' && c <= 'Z'));
}

int	ft_str_is_uppercase(char *str)
{
	int	is_upper;
	int	i;

	is_upper = 1;
	i = 0;
	while (str[i] != '\0' && is_upper == 1)
	{
		is_upper = is_upper_char(str[i]);
		++i;
	}
	return (is_upper);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_str_is_uppercase(av[1]));
}
*/
