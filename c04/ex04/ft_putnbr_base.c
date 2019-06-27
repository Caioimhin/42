/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:53:26 by kparis            #+#    #+#             */
/*   Updated: 2019/06/14 11:03:52 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int b;
	int tab[50];

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (!check_base(base))
		return ;
	i = 0;
	b = 0;
	while (base[b])
		b++;
	i = 0;
	while (nbr >= b)
	{
		tab[i] = nbr % b;
		nbr = nbr / b;
		i++;
	}
	tab[i] = nbr;
	while (i >= 0)
		ft_putchar(base[tab[i--]]);
}

int		main(int ac, char **av)
{
	ft_putnbr_base(atoi(av[1]), av[2]);
	return (0);
}
