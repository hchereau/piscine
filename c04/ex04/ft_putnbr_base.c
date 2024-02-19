/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:53:43 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/19 22:10:50 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

static void	fill_tab(bool *ascii_verif)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		if (i == '+' || i == '-' || (i < 32 && i > 126))
			ascii_verif[i] = true;
		else
			ascii_verif[i] = false;
		++i;
	}
}

static int	get_len_base(char *base)
{
	bool	ascii_verif[256];
	int		i;
	int		c;

	i = 0;
	fill_tab(ascii_verif);
	while (base[i] != '\0')
	{
		c = base[i];
		if (ascii_verif[c] == false)
			ascii_verif[c] = true;
		else
			return (0);
		++i;
	}
	return (i);
}

void	ft_putnbr_recursive(long nbr, char *base, int len_base)
{
	if (len_base > 1)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
		}
		if (nbr >= len_base)
		{
			ft_putnbr_recursive(nbr / len_base, base, len_base);
			write(STDOUT_FILENO, &base[nbr % len_base], 1);
		}
		else
			write(STDOUT_FILENO, &base[nbr % len_base], 1);
	}		
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_putnbr_recursive(nbr, base, get_len_base(base));
}
/*
#include <stdio.h>
int	main()
{
	ft_putnbr_base(2147483647, "0123456789ABCDEF");
}
*/
