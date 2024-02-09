/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/09 12:25:33 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ASCII_ZERO 48

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	print_comb(char nb1, char nb2, char nb3)
{
	ft_putchar(nb1);
	ft_putchar(nb2);
	ft_putchar(nb3);
	if (nb1 != '7' || nb2 != '8' || nb3 != '9')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	size_t	i;
	size_t	y;
	size_t	z;

	i = 0;
	y = 1;
	z = 2;
	while (i <= 7)
	{
		while (y <= 8)
		{
			while (z <= 9)
			{
				print_comb(i + ASCII_ZERO,
					y + ASCII_ZERO, z + ASCII_ZERO);
				++z;
			}
			++y;
			z = y + 1;
		}
		++i;
		y = i + 1;
		z = y + 1;
	}
}
