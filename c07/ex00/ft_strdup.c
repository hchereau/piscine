/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:19:09 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/21 09:37:26 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *src)
{
	const int	size = ft_strlen(src);
	char		*res;

	res = (char *)malloc(size * sizeof(char));
	if (res != NULL)
		ft_strlcpy(res, src, size + 1);
	return (res);
}
/*
#include <stdio.h>

int	main()
{
	char test[] = "salut";
	char *dest;

	dest = ft_strdup(test);
	printf("%s", dest);
}
*/
