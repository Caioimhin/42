/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:34:18 by kparis            #+#    #+#             */
/*   Updated: 2019/06/11 11:56:49 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_special(char str)
{
	if ((str < 'a' || str > 'z') &&
			(str < 'A' || str > 'Z') &&
			(str < '0' || str > '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int spe;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	i++;
	while (str[i] != '\0')
	{
		spe = ft_is_special(str[i - 1]);
		if ((spe == 0 && (str[i] >= 'a' && str[i] <= 'z')))
			str[i] = str[i] - 32;
		else if (spe == 1 && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
