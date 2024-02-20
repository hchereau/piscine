/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:43:23 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 08:52:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	prime = 0;

	if (nb <= 1)
		return (0);
	prime = 2;
	while (prime <= nb / prime)
	{
		if (nb % prime == 0)
			return (0);
		++prime;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		nb = 2;
	while (!ft_is_prime(nb))
		++nb;
	return (nb);
}


#include <stdio.h>

int main()
{
	printf("%d", ft_find_next_prime(2146483647))	
}
