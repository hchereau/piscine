/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:51:09 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/26 11:46:43 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	int			*tab_mid;
	const int	size = max - min;

	if (min >= max)
		return (NULL);
	tab_mid = (int *)malloc(size * sizeof(int));
	if (tab_mid == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab_mid[i] = min + i;
		++i;
	}
	return (tab_mid);
}
/*
int	main()
{
	int	*tab;

	ft_range()
}
*/
