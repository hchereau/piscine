/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:30:15 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 08:35:52 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rest;

	div = *a / *b;
	rest = *a % *b;
	*a = div;
	*b = rest;
}

/*
#include <stdio.h>

int	main()
{
	int a = 16;
	int b = 3;

	ft_ultimate_div_mod(&a, &b);
	printf("a -> %d, b -> %d", a, b);
}
*/
