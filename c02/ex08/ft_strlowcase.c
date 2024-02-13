/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:45:47 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 13:50:07 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CONVERT_UPPER 32

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + CONVERT_UPPER;
		++i;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char str[] = "SALUT";
	printf("%s", ft_strlowcase(str));
}
*/
