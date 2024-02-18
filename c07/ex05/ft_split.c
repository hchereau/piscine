/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:29 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/16 12:19:02 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlb.h>

char	**ft_split(char *str, char *charset)
{
	char	**split;
	size_t	count_word;
	size_t	size_word;
	size_t	i;
	size_t	word;

	split = (char **)malloc(count_word(str, charset) * sizeof(char *));
	word = 0;
	if (split != NULL)
	{
		i = 0;
		size_word = get_size_word(str + i, charset);
		split[word] = (char *)malloc(size_word * sizeof(char));
		while (i < size_word)
		{
			split[word][i] = str[i];  
			++i;
		}
	}
}

/*
process:
	-> compter le nombre de mots (count_words)
	-> verifier malloc
		-> compter le mot actuel
		-> 
	-> malloc pas bon
		-tout free (free_strs)
*/

