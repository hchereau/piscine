/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:48 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 18:29:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
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

int	get_size_join(char	**strs, int size)
{
	int	len_join;
	int	i;

	len_join = 0;
	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		len_join += ft_strlen(strs[i]);
		++i;
	}
	return (len_join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len_join;
	char	*strjoin;
	int		i;

	if (size < 0)
		return (0);
	if (size != 0 && strs != NULL)
		len_join = get_size_join(strs, size) + (ft_strlen(sep) * (size - 1));
	else
		len_join = 1;
	strjoin = (char *)malloc(len_join * sizeof(char));
	i = 0;
	*strjoin = '\0';
	if (strjoin != NULL && len_join != 0 && strs != NULL)
	{
		while (i < size)
		{
			ft_strlcat(strjoin, strs[i], len_join + 1);
			if (sep != NULL)
				ft_strlcat(strjoin, sep, len_join + 1);
			++i;
		}
		return (strjoin);
	}
	return (strjoin);
}
/*
#include <stdio.h>
int  main()
{
    char *strs[] = {"Hello", "42", "World", "piscine", "chat",
        "", "", ""};
    char *sep = "-*-";
    printf("%s\n", ft_strjoin(0, strs, sep));
}
*/
/*

process:
	-> trouver la taille de la grosse str (all str + size - 1 * sep)
	-> malloc la taille de la grosse chaine
	7-> remplir la string en copiant les morceaux puis les sep
	-> return la string
*/
