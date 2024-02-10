/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:50:37 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 09:22:59 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int	*tab, int size)
{
	int	swap;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			++i;
	}
}
/*
#include <stdio.h>

int main()
{
	int tab[5] = {9, 2, 7, 2, 3};
	ft_sort_int_tab(tab, 5);
	printf("%d, %d, %d, %d, %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}
*/
/*
	process:
		-> tant que i < size - 1
		-> prendre le nb str[i]
		-> verifier si str[i] > str[i + 1]
			->si oui, faire un swap entre str[i] et i + 1
			-> i = 0;
		-> sinon, ++i
*/
