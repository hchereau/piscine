/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:34:55 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 16:55:19 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = NULL;
	if (max <= min)
		return (0);
	*range = (int *)malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		++i;
	}
	return (max - min);
}
/*
#include <stdio.h>

int	main()
{
	int	*tab;
	int	i;
	int min = 11;
	int max = 25;

	ft_ultimate_range(&tab, max, min);
	i = 0;
	while (i < max - min && tab != NULL)
	{
		printf("%d\n", tab[i]);
		++i;
	}
	
}
*/
