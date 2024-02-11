/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:32:40 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 23:05:15 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
char	which_char(int ln, int col, int x, int y);
void	ft_putchar(char c);

void	print_line(int ln, int x, int y)
{
	int		col;
	char	c;

	col = 1;
	while (col <= x)
	{
		c = which_char(ln, col, x, y);
		ft_putchar(c);
		if (col == x)
			ft_putchar('\n');
		++col;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	write(1, str, i);
}

int	ft_atoi(char *str)
{
	int		idx;
	int		sign;
	int		value;

	idx = 0;
	value = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
	{
		value = value * 10 + str[idx] - '0';
		idx++;
	}
	return (value * sign);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) >= 0 && ft_atoi(av[2]) >= 0)
			rush(ft_atoi(av[1]), ft_atoi(av[2]));
		else
			ft_putstr("error : invalid arguments");
	}
	else
		ft_putstr("error : invalid arguments");
	return (0);
}
