/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:45:46 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/22 15:38:36 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi_base(char *str, char *base);
int	get_len_base(char *base);

static int size_number(int nb, int len_base)
{
	int size;

	size = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > len_base)
	{
		nb = nb / len_base;
		++size;
	}
	++size;
	return (size);
}

static int fill_string(int nb, char *base, int len_base, int len_number)
{
	while 
}

char	*ft_itoa_base(int nb, char *base)
{
	const int	len_base = get_len_base(base);
	const int	len_number = size_number(nb, len_base);
	char		*itoa;

	if (len_base > 1)
	{
		if (nb < 0)
		{
			itoa = (char *)malloc((len_number + 1)* sizeof(char));
			str[0] = '-';
			nb *= -1;
		}
		else
			itoa = (char *)malloc(len_number * sizeof(char));
		while ()
		{
			
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;

	nb = ft_atoi_base(nbr, base_from);
	return(ft_itoa_base(nb, base_to));
}

/*
	
	itoa_base
		-> but:
			-> transformer int en char * base
		args:
			-> char * base
			-> int nb
		process:
			-> trouver la len du nombre (division par len_base)
			-> copier le nombre pour le diviser par len de base puis ;odulo 
				len_base (tkt t'as capte)

	process:
		-> transformer le nombre en base 10 a partir de basefrom (atoi_base)
		-> transformer le int base 10 en base base_to (itoa_base)
		-> return nb
*/
