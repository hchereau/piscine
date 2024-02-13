/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:11 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 13:47:18 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FIRST_PRINTABLE_CHAR 32
#define LAST_PRINTABLE_CHAR 126

int	is_printable_char(char c)
{
	return (c >= FIRST_PRINTABLE_CHAR && c <= LAST_PRINTABLE_CHAR);
}

int	ft_str_is_printable(char *str)
{
	int	is_printable;
	int	i;

	is_printable = 1;
	i = 0;
	while (str[i] != '\0' && is_printable == 1)
	{
		is_printable = is_printable_char(str[i]);
		++i;
	}
	return (is_printable);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_str_is_printable("\n\t"));
}
*/
