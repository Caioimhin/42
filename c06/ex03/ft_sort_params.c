/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:21:59 by kparis            #+#    #+#             */
/*   Updated: 2019/06/16 10:19:08 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	affiche(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		sort;

	sort = 0;
	while (sort == 0)
	{
		i = 1;
		sort = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				sort = 0;
				str = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = str;
			}
			i++;
		}
	}
	affiche(argc, argv);
}
