/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:51:18 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 08:54:21 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t			size_dst;

	if (dst == NULL)
		size_dst = 0;
	else
		size_dst = ft_strlen(dst);
	if (size <= size_dst)
		return (size + size_src);
	ft_strlcpy(dst + size_dst, src, size - size_dst);
	return (size_dst + size_src);
}
