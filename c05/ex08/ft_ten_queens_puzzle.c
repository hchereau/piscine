/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:57:49 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/20 17:17:06 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_soluce(int matrix[10][10])
{
	char	str[11];
	int		i;
	int		col;

	i = 0;
	while (i < 10)
	{
		col = 0;
		while (matrix[col][i] == 0)
			++col;
		str[i] = col + '0';
		++i;
	}
	str[10] = '\n';
	write(1, str, 11);
}

int	is_valid_pion(int matrix[10][10], int line, int col)
{
	int	is_valid;
	int	diag_line;

	is_valid = 1;
	diag_line = 1;
	--col;
	while (col >= 0 && is_valid == 1)
	{
		if (matrix[line][col] == 1)
			is_valid = 0;
		else if (line - diag_line >= 0 && matrix[line - diag_line][col] == 1)
			is_valid = 0;
		else if (line + diag_line <= 9 && matrix[line + diag_line][col] == 1)
			is_valid = 0;
		++diag_line;
		--col;
	}
	return (is_valid);
}

int	place_pion(int matrix[10][10], int col)
{
	int	line;
	int	sol_count;

	line = 0;
	sol_count = 0;
	while (line < 10)
	{
		if (is_valid_pion(matrix, line, col))
		{
			matrix[line][col] = 1;
			if (col < 9)
				sol_count += place_pion(matrix, col + 1);
			else
			{
				sol_count++;
				print_soluce(matrix);
			}
			matrix[line][col] = 0;
		}
		line++;
	}
	return (sol_count);
}

int	ft_ten_queens_puzzle(void)
{
	int	matrix[10][10];
	int	i;

	i = -1;
	while (++i < 100)
		matrix[i / 10][i % 10] = 0;
	return (place_pion(matrix, 0));
}
/*
#include <stdio.h>

int main()
{
	printf("nombre soluce: %d", ft_ten_queens_puzzle());
}
*/
/*
	recall_pion
	-> process
		-> while  


	is_pion_valid
	pprocess:
		-> tant que col >= 0
			-> if matrix[line][col] == 1
				-> is_valid = false
			else if (matrix[--line][col] == 1)
				is_valid = false
			else if (matrix[++line][col] == 1)
				is_valid = false

	place pion
	process:
		-> verifier si le pion est valide (is_pion_valid)
			-> si oui
				-> placer le pion
				sinon virifier si col < 9
					-> si oui placer pion col + 1 avec line = 0
				sinon
					->print_soluce
					-> soluce + 1;
		-> si pion pas valide
			-> si line < 9
				-> line + 1
			-> sinon si col > 0
				-> si line de col - 1< 9
					-> rapeller au dernier pion + 1
			-> sinon 
				-> return soluce count;
*/
