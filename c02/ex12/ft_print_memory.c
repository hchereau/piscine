/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:54:30 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/16 11:49:14 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#define HEXA_BASE "0123456789abcdef"
#define SIZE 16

void	print_hexa(unsigned long value, int size_output)
{
	char		string_output[SIZE];
	size_t		padding;
	size_t		i;

	padding = size_output;
	if (padding > SIZE)
		padding = SIZE;
	i = 0;
	while (i < SIZE)
	{
		string_output[SIZE - i - 1] = HEXA_BASE[value % SIZE];
		value /= SIZE;
		++i;
	}
	write(STDOUT_FILENO, string_output + (SIZE - padding), size_output);
}

void	print_content(char	*str, size_t	size)
{
	while (size > 0)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			write(1, ".", 1);
		--size;
		++str;
	}
}

void	put_spaces(int size)
{
	while (size > 0)
	{
		write(1, " ", 1);
		write(1, " ", 1);
		if (size % 2 == 1)
			write(1, " ", 1);
		--size;
	}
}

void	print_char_hexa(char *line, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		print_hexa(*line, 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		++i;
		++line;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	ad;
	int				nb_bytes;
	int				count_bytes;

	nb_bytes = size;
	ad = (unsigned long)addr;
	while (nb_bytes > 0)
	{
		count_bytes = nb_bytes;
		if (count_bytes > 16)
			count_bytes = 16;
		print_hexa(ad, 16);
		write(1, ": ", 2);
		print_char_hexa(((char *)ad), count_bytes);
		put_spaces(16 - count_bytes);
		print_content(((char *)ad), count_bytes);
		write(1, "\n", 1);
		ad += 16;
		nb_bytes -= 16;
	}
	return (addr);
}

int	main()
{
	char *str = "Bonjour les aminches...c. est fou\ntout\tce qu on9 peut faire avec\e ..print_memory\n.\nlol.lol\n \n";
	ft_print_memory(str, 12000);
}
