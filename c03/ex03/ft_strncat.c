/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:50:09 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:39:51 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	size_t	i_dest;
	size_t	i_src;

	i_dest = 0;
	i_src = 0;
	while (dest[i_dest])
		++i_dest;
	while (i_src < nb && src[i_src])
	{
		dest[i_dest] = src[i_src];
		++i_dest;
		++i_src;
	}
	dest[i_dest] = '\0';
	return (i_dest;
}

