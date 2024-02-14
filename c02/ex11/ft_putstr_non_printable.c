/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 14:15:29 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXA_BASE "0123456789abcdef"

static void	print_hexa(const unsigned int nb)
{
	unsigned char		hexa[2];

	hexa[0] = HEXA_BASE[nb / 16];
	hexa[1] = HEXA_BASE[nb % 16];
	write(1, hexa, 2);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

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
	ft_putstr_non_printable("salut C'est super \n \t \r ouai \\ ");
}
*/
