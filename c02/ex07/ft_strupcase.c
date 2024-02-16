/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:45:47 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 13:41:20 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CONVERT_UPPER 32

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - CONVERT_UPPER;
		++i;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char str[] = "salut";
	printf("%s", ft_strupcase(str));
}
*/
