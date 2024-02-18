/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:10:19 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/18 18:10:54 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_matrix{

	int **matrix;
	int	size;
} t_matrix;

int		verif_vertical(t_matrix *matrix, int line, int col, int value);
int		verif_horizontal(t_matrix *matrix, int line, int col, int value);
int		verif_scrapt(t_matrix *matrix, int line, int col, int value);
int		**create_matrix(int size);
void	free_matrix(int **matrix, int size);
void	fill_matrix_borders(int **matrix, int size, char *arg);
void	place_scrapt(t_matrix *matrix, int line, int col, int value);

#endif
