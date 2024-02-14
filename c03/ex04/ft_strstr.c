/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:50:31 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:22:59 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

char	*ft_strstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			++j;
		}
		++i;
	}
	return (0);
}
