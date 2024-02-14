/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:47:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 08:49:52 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i_dest;
	int	i_src;

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
