/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:16:49 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/09 12:32:31 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_ZERO 48

void	fill_string(int nb1, int nb2, char *sol)
{
	sol[0] = nb1 / 10 + ASCII_ZERO;
	sol[1] = nb1 % 10 + ASCII_ZERO;
	sol[3] = nb2 / 10 + ASCII_ZERO;
	sol[4] = nb2 % 10 + ASCII_ZERO;
	sol[2] = ' ';
}

void	print_comb2(int nb1, int nb2)
{
	char	sol[5];

	fill_string(nb1, nb2, sol);
	write(1, sol, 5);
	if (nb1 != 98 || nb2 != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	while (nb1 < 100)
	{
		nb2 = nb1 + 1;
		while (nb2 < 100)
		{
			print_comb2(nb1, nb2);
			++nb2;
		}
		++nb1;
	}
}
