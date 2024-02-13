/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:11 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 10:37:32 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_char(char c)
{
	return ((c >= 'a' && c <= 'z') + (c >= 'A' && c <= 'Z'));
}

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;
	int	i;

	is_alpha = 1;
	i = 0;
	while (str[i] != '\0' && is_alpha == 1)
	{
		is_alpha = is_alpha_char(str[i]);
		++i;
	}
	return (is_alpha);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_str_is_alpha(av[1]));
}
*/
