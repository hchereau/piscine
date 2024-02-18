/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_scrapt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:25:04 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 19:37:40 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
void    print_matrix(int **matrix,int size)
{
    int i; 
    i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
        {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
int verif_scrapt(t_matrix *matrix, int line, int col, int value)
{
	if (verif_vertical(matrix, line, col, value))
	{
		if(verif_horizontal(matrix, line, col, value))
			return (1);
	}
	return (0);
}

static void  finish(t_matrix *matrix, int line, int col)
{
	if (col < matrix->size - 1)
		place_scrapt(matrix, line, col + 1, 1);
	else if (line < matrix->size - 1)
		place_scrapt(matrix, line + 1, 1, 1);
	else
		print_matrix(matrix->matrix, line);
}

void place_scrapt(t_matrix *matrix, int line, int col, int value)
{
	printf("col: %d, line: %d\n", col, line);
	print_matrix(matrix->matrix, matrix->size);
	if (verif_scrapt(matrix, line,  col, value))
	{
		matrix->matrix[line][col] = value;
		finish(matrix, line, col);
	}
	else if (value < matrix->size - 2)
	{
		printf("test\n");
		place_scrapt(matrix, line, col, value + 1);
	}
	else if (col > 1)
	{
		matrix->matrix[line][col] = 0;
		place_scrapt(matrix, line, col - 1, matrix->matrix[line][col - 1] + 1);
	}
	else if (line > 1)
	{
		matrix->matrix[line][col] = 0;
		place_scrapt(matrix, line - 1, 1, matrix->matrix[line - 1][matrix->size - 2] + 1);
	}
	else
		write(2, "ERROR\n", 5);
}


/*
	place_scrapt:
		but:
			placer un immeuble sur une case puis verifier si ca passe
		arg:
			-> t_matrix matrix (size / matrix)
			-> col du scrapt
			-> line du scrapt
			-> value du scrapt
		process:
			-> verifie si le scrapt est valide (is_valid_scrapt)
				-> si valid, on place le scrapt sur la matrice
					-> on rappelle place scrapt avec les bons args 
						(recall_place_scrapt)

	
	recall_place_scrapt:
			but:
				appeller place_scrapt avec les bons arg ou finir le programme
			arg:
				-> t_matrix matrix
				-> col
				-> line
			process:
				-> si col < n - 1
					-> on rapelle place scrapt avec col + 1 et value = 1
				-> si line < n - 1
					-> on rapelle place scrapt avec line + 1 col = 1, value = 1
				else
					print_matrix
					return(1)

*/
