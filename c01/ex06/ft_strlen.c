/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:41:45 by hucherea          #+#    #+#             */
/*   Updated: 2024/02/10 08:42:41 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}
