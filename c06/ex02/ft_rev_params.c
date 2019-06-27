/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:57:16 by kparis            #+#    #+#             */
/*   Updated: 2019/06/14 15:48:06 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;

	argc = argc - 1;
	while (argc)
	{
		i = 0;
		while (argv[argc][i])
			i++;
		write(1, argv[argc], i);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
