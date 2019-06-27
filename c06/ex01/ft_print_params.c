/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:24:50 by kparis            #+#    #+#             */
/*   Updated: 2019/06/14 15:49:07 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;
	int j;

	(void)argc;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
			i++;
		write(1, argv[j], i);
		write(1, "\n", 1);
		j++;
	}
	return (0);
}
