/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:02:32 by kparis            #+#    #+#             */
/*   Updated: 2019/06/27 10:37:11 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int			str_len(char *str, int i, char *charset)
{
	int count;

	count = 0;
	while (!check_sep(str[i], charset) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

int			ft_number(char *str, char *charset)
{
	int nb_str;
	int i;
	int found;

	found = 0;
	i = 0;
	nb_str = 0;
	while (str[i])
	{
		if (check_sep(str[i], charset) == 0 && str[i])
		{
			if (found == 0)
			{
				nb_str++;
				found = 1;
			}
		}
		else if (check_sep(str[i], charset) == 1 && str[i])
			found = 0;
		i++;
	}
	return (nb_str);
}

char		*create_str(char *str, char *charset, int i)
{
	char	*dest;
	int		j;

	j = 0;
	if (!(dest = malloc(sizeof(char) * str_len(str, i, charset) + 1)))
		return (NULL);
	while (str[i] && check_sep(str[i], charset) == 0)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char		**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char*) * (ft_number(str, charset) + 1))))
		return (NULL);
	while (str[i] && j < ft_number(str, charset))
	{
		while (check_sep(str[i], charset) == 1)
			i++;
		tab[j] = create_str(str, charset, i);
		j++;
		i++;
		while (str[i] && check_sep(str[i], charset) == 0)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
