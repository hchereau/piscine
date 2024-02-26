/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:29 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 19:08:16 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

bool	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset == NULL)
		return (0);
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
		{
			return (1);
		}
		++i;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int		i;
	int		count_word;
	bool	is_sepa;

	if (charset == NULL)
		return (1);
	count_word = 0;
	i = 0;
	is_sepa = false;
	while (is_sep(str[i], charset))
		++i;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && is_sepa == false)
		{
			++count_word;
			is_sepa = true;
		}
		else if (is_sep(str[i], charset))
			is_sepa = false;
		++i;
	}
	return (count_word);
}

int	get_len_word(char *str, int get_charset, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (is_sep(str[i], charset))
		++i;
	while (!is_sep(str[i], charset) && str[i] != '\0')
	{
		++i;
		++len;
	}
	if (get_charset)
		return (i);
	else
		return (len);
}

void	ft_strlcpy(char *dest, char *src, int len_word, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_sep(src[j], charset) && src[j] != '\0')
		++j;
	while (i < len_word && src[j + i] != '\0')
	{
		dest[i] = src[j + i];
		++i;
	}
	dest[len_word] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		nb_words;
	char	**split;
	int		i;
	int		total_len;
	int		len_word;

	i = 0;
	nb_words = count_words(str, charset);
	total_len = 0;
	split = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (split == NULL)
		return (split);
	while (i < nb_words)
	{
		len_word = get_len_word(str + total_len, 0, charset);
		split[i] = (char *)malloc((len_word + 1) * sizeof(char));
		ft_strlcpy(split[i], str + total_len, len_word, charset);
		total_len += get_len_word(str + total_len, 1, charset);
		++i;
	}
	split[nb_words] = NULL;
	return (split);
}
/*
#include <stdio.h>

int main()
{
	char str[] = "//\n///salut/mec//\n///comment/alors///\n///";
	char	**split = ft_split(NULL, "\nm");
	int		nb_words  = count_words(NULL, "\nm");
	int		i = 0;

	while (i < nb_words)
	{
		printf("[%s] ", split[i]);
		++i;
	}
}
*/
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
