/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_verification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:43:48 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 17:29:56 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int    is_not_same_number(t_matrix *matrix, int line, int value)
{
    int i;
    int    is_not_same_number;

    i = 1;
    is_not_same_number = 1;
    while (i < matrix->size - 1 && is_not_same_number == 1)
    {
        if (matrix->matrix[line][i] == 0)
            is_not_same_number = 1;
        else if (matrix->matrix[line][i] == value)
            is_not_same_number = 0;
        ++i;
    }
    return (is_not_same_number);
}

static    int horizontal_verif_left(t_matrix *matrix, int line)
{
    int    i;
    int    scrap_view;
    int    nb_max;

    i = 1;
    scrap_view = 0;
    nb_max = 0;
    while (i < matrix->size - 1)
    {
        if (matrix->matrix[line][i] == 0)
            return (1);
        if (matrix->matrix[line][i] > nb_max)
        {
            nb_max = matrix->matrix[line][i];
            ++scrap_view;
        }
        ++i;
    }
    if (scrap_view == matrix->matrix[line][0])
        return (1);
    else
        return (0);
}

static int    horizontal_verif_right(t_matrix *matrix, int line)
{
    int    i;
    int    scrap_view;
    int    nb_max;

    i = matrix->size - 2;
    scrap_view = 0;
    nb_max = 0;
    while (i > 0)
    {
        if (matrix->matrix[line][i] == 0)
            return (1);
        if (matrix->matrix[line][i] > nb_max)
        {
            nb_max = matrix->matrix[line][i];
            ++scrap_view;
        }
        --i;
    }
    if (scrap_view == matrix->matrix[line][0])
        return (1);
    else
        return (0);
}

int    verif_horizontal(t_matrix *matrix, int line, int col, int value)
{
    int    is_valid;

    is_valid = 0;
    if (is_not_same_number(matrix, line, value))
    {
        matrix->matrix[line][col] = value;
        if (horizontal_verif_left(matrix, line))
        {
            if (horizontal_verif_right(matrix, line))
                is_valid = 1;
        }
    }
    matrix->matrix[line][col] = 0;
    return (is_valid);
}

/*

process:
	-> verifier si c'est le meme nombre
	-> verifier la ligne par la gauche
	-> "    "    "  "" " " " "  droite

*/
