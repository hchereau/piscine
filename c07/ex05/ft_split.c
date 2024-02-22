/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:29 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/22 20:30:19 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlb.h>
#include <stddef.h>

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
		while (i <= size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len_word;
	int		nb_word;
	int		total_len;
	char	**split;
	char	*s_word;

	s_word = str;
	nb_word = count_word(str, charset);
	split = (char *)malloc(nb_word * sizeof(char));
	if (split != NULL)
	{
		while (i < nb_word)
		{
			get_len_word(s_word, &len_word, );
			total_len +=total_len;
			split[i] = (char *)malloc((len_word + 1) * sizeof(char));
			if (split[i] == NULL)
				return (0);
			ft_strlcpy(split[i], str + total_len, len_word + 1);
			++i;
		}
	}
}

/*
process:
	-> compter le nombre de mots (count_words)
	-> verifier malloc
		-> compter le nombre de mot
		-> malloc sur le nombre de mot
		-> pour chaque mot
			-> malloc sur strlen de mot
			-> remplir sur le mot jusqu'au separateur
			-> 
*/

