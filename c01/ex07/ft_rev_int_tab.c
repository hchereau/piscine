/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:43:26 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 08:50:07 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	end;
	int	conv;

	start = 0;
	end = size - 1;
	while (end > start)
	{
		conv = tab[start];
		tab[start] = tab[end];
		tab[end] = conv;
		++start;
		--end;
	}
}
/*
#include <stdio.h>

int main()
{
	int tab[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
	printf("%d, %d, %d, %d, %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}
*/
