/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:38:20 by kparis            #+#    #+#             */
/*   Updated: 2019/06/27 16:53:11 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

void	ft_write(int i)
{
	ft_putchar(i);
}

int main (int argc, char **argv)
{
	int *tab;
	void (*ptr)(int);

	ptr = &ft_write;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	ft_foreach(tab, 4, (*ptr));
	return (0);
}
