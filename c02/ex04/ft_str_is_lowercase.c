/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:11 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:25:03 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower_char(char c)
{
	return ((c >= 'a' && c <= 'z'));
}

int	ft_str_is_lowercase(char *str)
{
	int	is_lower;
	int	i;

	is_lower = 1;
	i = 0;
	while (str[i] != '\0' && is_lower == 1)
	{
		is_lower = is_lower_char(str[i]);
		++i;
	}
	return (is_lower);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_str_is_lowercase(av[1]));
}
*/
