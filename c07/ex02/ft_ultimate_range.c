/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:33:08 by kparis            #+#    #+#             */
/*   Updated: 2019/06/20 16:59:33 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int size;
	int i;

	tab = NULL;
	if (min >= max)
	{
		*range = tab;
		return (0);
	}
	size = max - min;
	*range = tab;
	if (!(tab = malloc(sizeof(int) * size + 1)))
		return (-1);
	i = 0;
	while (i < size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (size);
}
