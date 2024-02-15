/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:02:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/15 11:50:49 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define HEXA_BASE "0123456789abcdef"
#define SIZE 16

unsigned char	get_hex_digit(unsigned char c, int is_first_digit)
{
	if (is_first_digit)
		return (HEXA_BASE[c >> 4]);
	return (HEXA_BASE[c & 0x0F]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	digit;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			digit = get_hex_digit(str[i], 1);
			write(1, &digit, 1);
			digit = get_hex_digit(str[i], 0);
			write(1, &digit, 1);
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
