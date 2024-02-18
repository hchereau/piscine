/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_verification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:39:51 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 19:38:53 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	is_not_same_number(t_matrix *matrix, int col, int value)
{
	int i;
	int	is_not_same_number;

	i = 1;
	is_not_same_number = 1;
	while (i < matrix->size - 1 && is_not_same_number == 1)
	{
		if (matrix->matrix[i][col] == 0)
			is_not_same_number = 1;
		else if (matrix->matrix[i][col] == value)
			is_not_same_number = 0;
		++i;
	}
	return (is_not_same_number);
}

static	int vertical_verif_up(t_matrix *matrix, int col)
{
	int	i;
	int	scrap_view;
	int	nb_max;

	i = 1;
	scrap_view = 0;
	nb_max = 0;
	while (i < matrix->size - 1)
	{
		if (matrix->matrix[i][col] == 0)
			return (1);
		if (matrix->matrix[i][col] > nb_max)
		{
			nb_max = matrix->matrix[i][col];
			++scrap_view;
		}
		++i;
	}
	if (scrap_view == matrix->matrix[0][col])
		return (1);
	else
		return (0);
}

static int	vertical_verif_down(t_matrix *matrix, int col)
{
	int	i;
	int	scrap_view;
	int	nb_max;

	i = matrix->size - 2;
	scrap_view = 0;
	nb_max = 0;
	while (i > 0)
	{
		if (matrix->matrix[i][col] == 0)
			return (1);
		if (matrix->matrix[i][col] > nb_max)
		{
			nb_max = matrix->matrix[i][col];
			++scrap_view;
		}
		--i;
	}
	if (scrap_view == matrix->matrix[0][col])
		return (1);
	else
		return (0);
}

int	verif_vertical(t_matrix *matrix, int line, int col, int value)
{
	int	is_valid;

	is_valid = 0;
	if (is_not_same_number(matrix, col, value))
	{
		matrix->matrix[line][col] = value;
		if (vertical_verif_up(matrix, col))
		{
			if (vertical_verif_down(matrix, col))
				is_valid = 1;
		}
	}
	matrix->matrix[line][col] = 0;
	return (is_valid);
}

/*
	vertical_verification:
		-> verifier si on a les meme nombres
		-> verifier la ligne en partant du haut
		-> verifier la ligne en partant du bas


	vertical_verification_up
	-> tant que i < size - 2
		-> if mat[i]][i
*/


