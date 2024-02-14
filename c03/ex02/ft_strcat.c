/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:47:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:20:10 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

char	*ft_strcat(char *dest, char *src)
{
	size_t	i_dest;
	size_t	i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest] != '\0')
		++i_dest;
	while (src[i_src] != '\0')
	{
		dest[i_dest] = src[i_src];
		++i_dest;
		++i_src;
	}
	dest[i_dest] = '\0';
	return (dest);
}
