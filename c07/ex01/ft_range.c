/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:51:09 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/21 11:34:17 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab_mid;

	tab_mid = (int *)malloc((max - min) * sizeof(int));
	i = min
	while (i <= max)
	{
		tab_mid[i - min] = i;
		++i;
	}
	return (tab_mid);
}
