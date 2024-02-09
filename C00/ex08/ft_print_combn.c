/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:36:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/09 12:42:38 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_ZERO 48

static void	ft_putnbr(int nb, int p_zero, int n, int len_nb)
{
	char	char_nb;

	if (p_zero == 0)
	{
		while (n - len_nb > 0)
		{
			write(1, "0", 1);
			--n;
		}
	}
	if (nb > 9)
		ft_putnbr(nb / 10, 1, n, len_nb);
	char_nb = nb % 10 + ASCII_ZERO;
	write(1, &char_nb, 1);
}

static int	is_valid_number(int nb)
{
	int	is_same_nb;
	int	is_decroissant;
	int	same;
	int	decrois;

	is_decroissant = 1;
	decrois = 10;
	if (nb < 10)
		is_same_nb = 1;
	else
		is_same_nb = 0;
	same = nb % 10;
	while (nb > 0)
	{
		if (nb % 10 != same)
			is_same_nb = 1;
		if (decrois < nb % 10)
			is_decroissant = 0;
		decrois = nb % 10;
		nb = nb / 10;
	}
	return (is_same_nb + is_decroissant);
}

static int	last_number(int n)
{
	int	i;
	int	last_nb;
	int	puiss;
	int	nb_puis;

	last_nb = 0;
	i = 0;
	while (n > 0)
	{
		puiss = 0;
		nb_puis = 9 - i;
		while (puiss < i)
		{
			nb_puis *= 10;
			++puiss;
		}
		last_nb += nb_puis;
		--n;
		++i;
	}	
	return (last_nb);
}

static void	print_nb(int nb, int n)
{
	int	len_nb;
	int	nb_cpy;

	len_nb = 0;
	nb_cpy = nb;
	while (nb_cpy > 0)
	{
		nb_cpy = nb_cpy / 10;
		++len_nb;
	}
	if (nb > 0)
		ft_putnbr(nb, 0, n, len_nb);
	if (nb != last_number(n) && nb > 0)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	i;
	int	last_nb;

	if (n < 0 && n > 10)
	{
		i = 0;
		last_nb = last_number(n);
		while (i <= last_nb)
		{
			if (is_valid_number(i) == 2)
				print_nb(i, n);
			++i;
		}
	}
}
