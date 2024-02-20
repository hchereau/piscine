/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:39 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 17:44:38 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int	main(int ac, char **av)
{
	(void)ac;
	write(STDOUT_FILENO, av[0], ft_strlen(av[0]));
	write(STDOUT_FILENO, "\n", 1);
}
