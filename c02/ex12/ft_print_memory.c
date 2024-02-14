/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:54:30 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/14 08:41:19 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#define HEXA_BASE "0123456789abcdef"
/*
void	print_address(unsigned long addr, const char *base)
{
	char	add_first_char[16];
	int		fill;
	size_t	i;

	fill = 0;
	while(fill < 16)
	{
		add_first_char[fill] = '0';
		++fill;
	}
	i = 15;
	while (addr >= 16)
	{
		add_first_char[i] = base[addr % 16];
		addr = addr / 16;
		--i;
	}
	add_first_char[i] = base[addr % 16];
	write(1, add_first_char, 16);
	write(1, ": ", 2);
}

void	print_char_hexa(char *addr, const char *base, int	size)
{
	char	oct_hexa[2];
	int		i_address;

	i_address = 0;
	while(i_address < size)
	{
		oct_hexa[0] = base[*addr / 16];
		oct_hexa[1] = base[*addr % 16];
		write(1, oct_hexa, 2);
		if (i_address % 2 == 1)
			write(1, " ", 1);
		++addr;
		++i_address;
	}
}
*/

void	print_hexa(unsigned long value, int size_output)
{
	char	string_output[16] = {'0'};
	char		*hex_digit = HEXA_BASE;
	size_t		i;

	i = size_output;
	while (i > 0)
	{
		string_output[i - 1] = hex_digit[value % 16];
		value = value / 16;
		--i;
	}
	write(1, &string_output[16 - size_output], size_output);
}

void	print_content(char	*str, size_t	size)
{
	while(size > 0)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			write(1, ".", 1);
		--size;
		++str;
	}
}

void	put_spaces(int	size)
{
	while (size > 0)
	{
		write(1 ," ", 1);
		write(1 ," ", 1);
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
	 int			nb_bytes;

	nb_bytes = size;
	ad = (unsigned long)addr;
	while (nb_bytes > 0)
	{
		print_hexa(ad, 16);
		if (nb_bytes > 16)
		{
			print_char_hexa(((char *)ad), 16);
			print_content(((char *)ad), 16);
		}
		else
		{
			print_char_hexa(((char *)ad), nb_bytes);
			put_spaces(16 - nb_bytes);
			print_content(((char *)ad), nb_bytes);
		}
		write(1, "\n", 1);
		ad += 16;
		nb_bytes -= 16;
	}
	return(addr);
}

int	main()
{
	char *str = "Bonjour les aminches...c. est fou\ntout\tce qu on9 peut faire avec\e ..print_memory\n.\nlol.lol\n \n";
	ft_print_memory(str, 91);
}
/*
addr = unsigned long

convert_hexa:
but:
	-> afficher adresse en hexa
args:
	-> unsigned long addr
process:
	-> 

	
process:
	-> 


process:
	-> convertir l'adresse en hexa (convert hexa)
	-> afficher l'adresse )
	-> convertir la valeur d'un char en hexa, les char sont grouupes par deux
		et separe  par des espaces.
	-> afficher la string


*/
