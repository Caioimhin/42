/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:03:52 by kparis            #+#    #+#             */
/*   Updated: 2019/06/12 10:07:26 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_digit(int nb)
{
	int	i;
	int	nb_digit;
	int	neg;

	neg = 0;
	nb_digit = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	i = nb;
	while (i != 0)
	{
		i = i / 10;
		nb_digit++;
	}
	return (nb_digit);
}

int		check_neg(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

void	write_nb(int digit, int nb)
{
	char	tab[digit];
	int		count;
	int		x;
	int		neg;

	neg = check_neg(nb);
	if (neg == 1)
		nb = nb * -1;
	count = digit;
	while (count > 0)
	{
		tab[count] = nb % 10;
		nb = nb / 10;
		count--;
	}
	x = 1;
	if (neg == 1)
		write(1, "-", 1);
	while (x <= digit)
	{
		tab[x] = tab[x] + 48;
		write(1, &tab[x], 1);
		x++;
	}
}

void	ft_putnbr(int nb)
{
	int nb_digit;

	nb_digit = get_digit(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
		write_nb(nb_digit, nb);
}
