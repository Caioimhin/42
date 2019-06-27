/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:08:35 by kparis            #+#    #+#             */
/*   Updated: 2019/06/27 14:43:23 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_map(int *tab, int length, int (*f)(int))
{
	int *ret_tab;
	int i;

	i = 0;
	ret_tab = NULL;
	if (!(ret_tab = malloc(sizeof(int) * length)))
		return (ret_tab);
	while (tab[i])
	{
		ret_tab[i] = f(tab[i]);
		i++;
	}
	return (ret_tab);
}
