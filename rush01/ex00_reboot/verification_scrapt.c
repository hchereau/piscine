/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_scrapt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:36:17 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 17:28:35 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	 verif_scrapt(t_matrix *matrix, int line, int col, int value)
{
	if(verif_horizontal(matrix, line, col, value))
	{
		if (verif_vertical(matrix, line, col, value))
			return (1);
	}
	return (0);
}


/*
	is_valid_scrapt
		but:
			verifier si le scrapt est bon
		arg:
			-> verifier la ligne vertical (vertical_verification)
			-> verifier la ligne horizontal (horizontal_verification)
*/
