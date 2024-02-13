/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/12 18:49:13 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	print_hexa(int nb)
{
	const char	base[] = "0123456789abcdef";
	char		hexa[2];

	hexa[0] = base[nb / 16];
	hexa[1] = base[nb % 16];
	write(1, hexa, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			print_hexa(str[i]);
		}
		++i;
	}
}
/*
int	main()
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
*/