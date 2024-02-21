/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:42:57 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 18:57:09 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

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
	--ac;
	while (ac > 0)
	{
		ft_putstr(av[ac]);
		write(STDOUT_FILENO, "\n", 1);
		--ac;
	}
	return (0);
}
