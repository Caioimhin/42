/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dico.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:07:59 by amartin-          #+#    #+#             */
/*   Updated: 2019/06/23 18:02:22 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_write_in_letters(char *dico, int i)
{
	while (dico[i] == ' ')
		i++;
	if (dico[i] == ':')
		i++;
	while (dico[i] == ' ')
		i++;
	while (dico[i] != '\n')
	{
		while (dico[i] == ' ')
		{
			while (dico[i] == ' ')
				i++;
			ft_putchar(' ');
		}
		ft_putchar(dico[i++]);
	}
	return (0);
}

char	*ft_one_number_to_letters(char *nb_digits, char *dico)
{
	int		i;
	int		j;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while (dico[i] == nb_digits[j] && dico[i] && nb_digits[j++])
			i++;
		if (nb_digits[j] == '\0' && (dico[i] == ' ' || dico[i] == ':'))
		{
			ft_write_in_letters(dico, i);
			while (dico[i])
				i++;
		}
		i++;
	}
	return (0);
}

char	*view_dico(void)
{
	int		fd;
	char	*dico;
	int		ret_read;

	fd = open("numbers.dict.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return ("error");
	}
	dico = malloc(sizeof(dico) * 4096);
	ret_read = read(fd, dico, 4096);
	dico[ret_read] = '\0';
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return ("error");
	}
	return (dico);
}
