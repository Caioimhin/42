/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:02:37 by kparis            #+#    #+#             */
/*   Updated: 2019/06/23 23:26:50 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "our_library.h"

int			str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*get_1000(int len)
{
	char	*unit;
	int		i;

	if (!(unit = malloc(sizeof(char) * len * 2 + 1)))
	{
		ft_putstr("Error\n");
		exit(2);
	}
	unit[0] = '1';
	i = 1;
	while (len > 1)
	{
		unit[i] = '0';
		i++;
		len--;
	}
	unit[i] = 0;
	return (unit);
}

int			errors(void)
{
	ft_putstr("Error\n");
	exit(2);
}

void		if_zero(char *str)
{
	ft_one_number_to_letters("0", view_dico());
	exit(2);
}

void		ft_espace(char *str, int i)
{
	while (str[i])
	{
		if (str[++i] != '0')
		{
			write(1, " ", 1);
			break ;
		}
	}
}
