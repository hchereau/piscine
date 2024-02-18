/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:15:10 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 16:27:37 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int **create_matrix(int size)
{
	int **matrix;
	int i;
	int j;

	matrix = (int **)malloc((size + 2) * sizeof(int *));
	if (matrix == NULL)
	{
		printf("error memory allocation faled for matrix rows");
		return NULL;
	}
	
	i = 0;
	while (i < size + 2)
	{
		matrix[i] = (int *)malloc((size + 2) * sizeof(int));
		if(matrix[i] == NULL)
		{	
			printf("error emory for rows");
			while(--i >= 0)
			{
				free(matrix[i]);
			}
			free(matrix);
			return(NULL);
		}
		j = 0;
		while (j < size + 2)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return matrix;
}

void free_matrix(int **matrix, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		free(matrix[i]); 
		i++;
	}
	free(matrix);
}


void fill_matrix_borders(int **matrix, int size, char *arg)
{
	int position = 0;
	int argv_count = 0;

	while (position < size)
	{
		matrix[0][position + 1] = (arg[argv_count] - '0');
		position++;
		argv_count += 2;
	}
	position = 0;
	while (position < size)
	{
		matrix[size + 1][position + 1] = (arg[argv_count] - '0');
		position++;
		argv_count += 2;

	}
	position = 0;
	while (position < size)
	{
		matrix[position + 1][0] = (arg[argv_count] - '0');
		position++;
		argv_count += 2;

	}
	position = 0;
	while (position < size)
	{
		matrix[position + 1][size + 1] = (arg[argv_count] - '0');
		position++;
		argv_count += 2;

	}
}

/*
fill_matrix:
	but:
		malloc la matrix  puis la rempplir de 0 et des point de vue
	argument:
		-> t_matrix matrix (matrix et size pour le test)
	process:
		-> malloc uun tableau de tableau de int sur size + 2
		-> parcourir la matrix sur les tableau de int
			-> malloc les tableau de int sur size + 2
			->parourir les tableaux de int
				-> les remplir de 0;
		remplir la matrice des pt_on_view (fill_pt_view)
	
fill_pt_view:
	but:
		->remplir la matrice des pt_on view



*/
