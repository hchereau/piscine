/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:34:55 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/21 18:46:57 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (NULL);
	i = min;
	while (i < max)
	{
		(*range)[i - min] = i;
		++i;
	}
	return (max - min);
}
