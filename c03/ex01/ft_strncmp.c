/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:52:49 by kparis            #+#    #+#             */
/*   Updated: 2019/06/12 19:34:25 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char string1;
	char string2;

	while (n > 0)
	{
		string1 = *s1++;
		string2 = *s2++;
		if (string1 != string2)
			return (string1 - string2);
		if (string2 == '\0')
			return (0);
		n--;
	}
	return (0);
}
