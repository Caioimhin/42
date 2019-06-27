/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:17:56 by kparis            #+#    #+#             */
/*   Updated: 2019/06/21 10:55:40 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		my_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		get_size(int size, char **strs, char *sep)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += my_strlen(strs[i]);
		i++;
	}
	j = 0;
	while (j != size - 1)
	{
		len += my_strlen(sep);
		j++;
	}
	return (len);
}

char	*bad_size(char *dest)
{
	dest[0] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	dest = malloc(sizeof(char) * (get_size(size, strs, sep) + 1));
	if (!size)
		return (bad_size(dest));
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		j = 0;
		if (i + 1 < size)
		{
			while (sep[j])
				dest[k++] = sep[j++];
		}
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
