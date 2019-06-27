/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:46:56 by kparis            #+#    #+#             */
/*   Updated: 2019/06/06 11:17:57 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 47;
	while (++a <= 55)
	{
		b = a;
		while (++b <= 56)
		{
			c = b;
			while (++c <= 57)
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (a != 55)
				{
					ft_putchar(44);
					ft_putchar(32);
				}
			}
		}
	}
}
