/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:58 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 18:50:00 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	main(int ac, char **av)
{
	int	i;
	
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (0);
}
