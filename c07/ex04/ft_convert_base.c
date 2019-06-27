/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:14:12 by kparis            #+#    #+#             */
/*   Updated: 2019/06/19 14:18:48 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int		ft_str_is_alphanumeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' &&
					str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		str++;
	}
	return (1);
}

int		check_base(char *base)
{
	int i;
	int n;

	i = 0;
	while (base[i])
	{
		if (ft_str_is_alphanumeric(base))
			return (0);
		n = 0;
		while (n < i)
		{
			if (base[n] == base[i])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int nb;

	nb = ft_atoi(nbr);
	if (!check_base(base_from) || !check_base(base_to))
		return NULL;
}
