/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:51:18 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:21:29 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

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
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	const size_t	size_src = ft_strlen(src);
	size_t			size_dest;

	if (dest == NULL)
		size_dest = 0;
	else
		size_dest = ft_strlen(dest);
	if (size <= size_dest)
		return (size + size_src);
	ft_strlcpy(dest + size_dest, src, size - size_dest);
	return (size_dest + size_src);
}
