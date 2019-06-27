/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:15:16 by kparis            #+#    #+#             */
/*   Updated: 2019/06/25 22:09:47 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "our_library.h"

void		hundreds(char *val, char *str, int i)
{
	val[0] = str[i];
	val[1] = '\0';
	ft_one_number_to_letters(val, view_dico());
	write(1, " ", 1);
	val = "100";
	ft_one_number_to_letters(val, view_dico());
	while (str[++i])
	{
		if (str[i] != '0')
		{
			write(1, " ", 1);
			break ;
		}
	}
}

void		decade(char *val, char *str, int i, int len)
{
	if (str[i] == '1')
	{
		val[0] = str[i];
		val[1] = str[i + 1];
		val[2] = 0;
		ft_one_number_to_letters(val, view_dico());
		if (len > 2)
		{
			write(1, " ", 1);
			val = get_1000(len - 1);
			ft_one_number_to_letters(val, view_dico());
			ft_espace(str, i);
		}
	}
	else
	{
		val[0] = str[i];
		val[1] = '0';
		val[2] = 0;
		ft_one_number_to_letters(val, view_dico());
		if (str[i + 1] != '0')
			write(1, " ", 1);
	}
}

void		unite(char *val, int len, char *str, int i)
{
	val[0] = str[i];
	val[1] = 0;
	ft_one_number_to_letters(val, view_dico());
	if (len > 2)
	{
		write(1, " ", 1);
		val = get_1000(len);
		ft_one_number_to_letters(val, view_dico());
		while (str[i])
		{
			if (str[++i] != '0')
			{
				write(1, " ", 1);
				break ;
			}
		}
	}
}

void		break_number(char *str)
{
	int		i;
	int		len;
	char	*val;

	i = 0;
	len = str_len(str);
	while (str[i] && len > 0)
	{
		val = malloc(sizeof(char) * len + 1);
		if (len % 3 == 0 && str[i] != '0')
			hundreds(val, str, i);
		if (len % 3 == 1 && str[i] != '0')
			unite(val, len, str, i);
		if (len % 3 == 2 && str[i] != '0')
		{
			decade(val, str, i, len);
			if (str[i] == '1')
			{
				len--;
				i++;
			}
		}
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
