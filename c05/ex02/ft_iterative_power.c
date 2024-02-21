/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:51:19 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/21 08:19:40 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	puis;

	puis = nb;
	if (power < 0)
		return (0);
	if (power == 1 || power == 0)
		return (nb);
	while (power > 0)
	{
		nb *= puis;
		--power;
	}
	return (nb);
}
