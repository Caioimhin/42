/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:16 by kparis            #+#    #+#             */
/*   Updated: 2019/06/23 19:55:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "our_library.h"

void		hundreds(char *val, char c)
{
	val[0] = c;
	val[1] = '\0';
	ft_one_number_to_letters(val, view_dico());
	write(1, " ", 1);
	val = "100";
	ft_one_number_to_letters(val, view_dico());
	write(1, " ", 1);
}

int			decade(char *val, int p, char *str, int i)
{
	if (str[i] == '1')
	{
		val[0] = str[i];
		val[1] = str[i + 1];
		val[2] = 0;
		p = 1;
		ft_one_number_to_letters(val, view_dico());
		write(1, " ", 1);
		i++;
	}
	else
	{
		val[0] = str[i];
		val[1] = '0';
		val[2] = 0;
		ft_one_number_to_letters(val, view_dico());
		write(1, " ", 1);
	}
	return (i);
}

void		unite(char *val, int p, int len, char c)
{
	if (p != 1)
	{
		val[0] = c;
		val[1] = 0;
		ft_one_number_to_letters(val, view_dico());
	}
	p = 0;
	if (len > 2)
	{
		write(1, " ", 1);
		val = get_1000(len);
		ft_one_number_to_letters(val, view_dico());
		write(1, " ", 1);
	}
}

void		break_number(char *str)
{
	int		i;
	int		p;
	int		len;
	char	*val;

	i = 0;
	p = 0;
	len = str_len(str);
	while (str[i])
	{
		val = malloc(sizeof(char) * len + 1);
		if (!val)
			errors();
		if (len % 3 == 0 && str[i] != '0')
			hundreds(val, str[i]);
		if (len % 3 == 2 && str[i] != '0')
			i = decade(val, p, str, i);
		if (len % 3 == 1 && str[i] != '0')
			unite(val, p, len, str[i]);
		len--;
		i++;
	}
}

int			main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_putstr("Error\n");
			return (-1);
		}
		i++;
	}
	if (str_len(argv[1]) == 1 && argv[1][0] == '0')
		if_zero(argv[i]);
	break_number(argv[1]);
	return (0);
}
