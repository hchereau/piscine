/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:56:30 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/15 11:14:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CONVERT_MAJ 32

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + CONVERT_MAJ;
		++i;
	}
	return (str);
}

int	is_alpha_numeric(char c)
{
	int	is_alpha_numeric;

	is_alpha_numeric = 0;
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		is_alpha_numeric = 1;
	return (is_alpha_numeric);
}

int	is_word(char c)
{
	int	is_word;

	is_word = 0;
	if (is_alpha_numeric(c))
		++is_word;
	return (is_word);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (is_word(str[i]) && in_word == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - CONVERT_MAJ;
			in_word = 1;
		}
		else if (!is_word(str[i]))
			in_word = 0;
		++i;
	}
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char str[] = "524hjkl //p/PP gd\t%$# ^y\\t^ 58\n";
	printf("%s", ft_strcapitalize(str));
}
*/
