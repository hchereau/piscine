/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 10:37:12 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 15:26:20 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int ln, int x, int y);

static char	first_line(int col, int x)
{
	char	c;

	if (col == 1)
		c = 'A';
	else if (col == x)
		c = 'C';
	else
		c = 'B';
	return (c);
}

static char	last_line(int col, int x)
{
	char	c;

	if (col == 1)
		c = 'C';
	else if (col == x)
		c = 'A';
	else
		c = 'B';
	return (c);
}

static char	middle_line(int col, int x)
{
	char	c;

	if (col == 1 || col == x)
		c = 'B';
	else
		c = ' ';
	return (c);
}

char	which_char(int ln, int col, int x, int y)
{
	char	c;

	if (ln == 1)
		c = first_line(col, x);
	else if (ln == y)
		c = last_line(col, x);
	else
		c = middle_line(col, x);
	return (c);
}

void	rush(int x, int y)
{
	int	ln;

	ln = 1;
	while (ln <= y)
	{
		print_line(ln, x, y);
		++ln;
	}
}
/*
	wich_char
		-> but: choisir le char
	
		-> valeur de retour: char c, c est le char choisis

		-> args: ln qui est la ligne, col qui est la colonne;

		-> fonctionnement de la fonction:
			-> si ln est egal a 1
				-> if (col == 1)
					-> char choisi 'A'
				-> sinon si colonne qui est egal a y
					-> char choisi 'A'
				-> sinon
					char choisi 'B'
			-> si ln est egal x
				-> si col == 1
					char choisi 'C'
				-> sinon si col est egal y
					char choisi 'C'
				-> sinon
					char choisi 'B'
			-> sinon
				-> si y et plus petit que y et plus grand que 1
					char choisi = ' '
				-> sinon
					char choisi = 'B'
			return(char)

				

	print_line:
		-> but: afficher une ligne, avec une taille egal a x
			
		-> args: int ln la ligne actuelle, int x qui est la longueur de la ligne

		-> fonctionnement de la fonction:
				-> tant que i est plus petit ou egal a x
					-> trouve le char a afficher (which_char)
					-> affiche le cahr
					-> affiche un retour a la ligne
					-> ++i;
						

	rush_base:
		-> but : afficher un rectangle, en fonction de du parametre colonne
				et du parametre ligne
		
		-> argument : int x pour les colonnes | int y pour les lignes

		-> fonctionnnement de la fonction:
				-> tant que ln est plus petit ou egal a y
					-> affiche une ligne avec les characteres valident (print_line)
					-> ln + 1;
				
*/
