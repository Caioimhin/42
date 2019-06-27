/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:42:28 by kparis            #+#    #+#             */
/*   Updated: 2019/06/07 14:50:04 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_digit(int nb)
{
	int x;
	int nb_digit;

	nb_digit = 0;
	x = nb;
	while (x != 0)
	{
		x = x / 10;
		nb_digit++;
	}
	return (nb_digit);
}

void	write_nb(int digit, int nb)
{
	char	tab[digit];
	int		count;
	int		x;

	count = digit;
	while (count > 0)
	{
		tab[count] = nb % 10;
		nb = nb / 10;
		count--;
	}
	x = 1;
	while (x <= digit)
	{
		tab[x] = tab[x] + 48;
		write(1, &tab[x], 1);
		x++;
	}
}

void	ft_putnbr(int nb)
{
	int digit;

	digit = get_digit(nb);
	write_nb(digit, nb);
}

int		main(void)
{
	ft_putnbr(42);
	return (0);
}
