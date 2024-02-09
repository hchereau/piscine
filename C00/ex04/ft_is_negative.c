/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:29:55 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/09 12:19:28 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char	is_neg;

	if (n >= 0)
		is_neg = 'P';
	else
		is_neg = 'N';
	ft_putchar(is_neg);
}
