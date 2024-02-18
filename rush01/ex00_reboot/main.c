/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:10:06 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 19:23:41 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_matrix	matrix;
    matrix.size = 4;
    matrix.matrix = create_matrix(matrix.size);
	fill_matrix_borders(matrix.matrix,matrix.size,argv[1]);
	matrix.size += 2;
	place_scrapt(&matrix, 1, 1, 1);
    return (0);
}


/*

process:
	-> remplir matrix de 0 (fill_matrix)
	-> lancer le backtracking (place scrapt)


*/

