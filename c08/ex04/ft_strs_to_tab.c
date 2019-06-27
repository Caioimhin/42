/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 12:58:08 by kparis            #+#    #+#             */
/*   Updated: 2019/06/25 10:42:25 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	char	*str2;
	int		i;
	int		src_len;

	i = 0;
	src_len = str_len(src);
	if (!(str2 = malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	while (src[i])
	{
		str2[i] = src[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = NULL;
	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (tab);
	while (i < ac)
	{
		tab[i].size = str_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
