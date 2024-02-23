/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:29 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/23 10:02:22 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlb.h>
#include <stddef.h>

int	count_word(char *str, char *charset)
{
	int	i;
	int	count_word;

	while (str[i] != '\0')
	{
		while ()
		++i;
	}
}

void	ft_strlcpy(char *dest, char *src, unsigned int size)
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
}

void	get_len_word(char *s_word, int len_word, char *charset)
{
	while(!is_sep(*s_word, charset))
	{
		++s_word;
		++len_word;
	}
	++s_word;
	while(is_sep(*s_word, charset))
		++s_word;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len_word;
	int		nb_word;
	char	**split;
	char	*s_word;

	s_word = str;
	nb_word = count_word(str, charset);
	split = (char *)malloc(nb_word * sizeof(char));
	if (split != NULL)
	{
		while (i < nb_word)
		{
			len_word = 0;
			get_len_word(s_word, &len_word, charset);
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

