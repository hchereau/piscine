/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:02:38 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 19:13:36 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int ac, char **av)
{
	int i_start;
	int	i_tri;

	i_start = 0;
	while (i_start < ac)
	{
		i_tri = 0;
		while (i_tri < ac)
		{
			if (strcmpt(av[i_start], av[i_tri]))
			{
				ft_swap
			}
		}
	}
}
