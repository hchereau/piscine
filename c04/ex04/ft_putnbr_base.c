/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:53:43 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/16 10:11:58 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

static void	fill_tab(bool *ascii_verif)
{
	size_t	i;

	i = 0;
	while (i < 128)
	{
		if (i == '+' || i == '-')
			ascii_verif[i] = true;
		else
			ascii_verif[i] = false;
		++i;
	}
}

static int get_len_base(char *base)
{
	bool	ascii_verif[128];
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

void	ft_putnbr_recursive(int nbr, char *base, int len_base)
{
	if (len_base > 1 && nbr > len_base)
	{
		ft_putnbr_recursive(nbr / len_base, base, len_base);
		write(STDOUT_FILENO, &base[nbr % len_base], 1);
	}
	else if (len_base > 1)
		write(STDOUT_FILENO, &base[nbr], 1);
		
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_putnbr_recursive(nbr, base, get_len_base(base));
}

int	main()
{
	ft_putnbr_base(65, "0123456789ABCDEF");
}
