/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:18:42 by kparis            #+#    #+#             */
/*   Updated: 2019/06/21 15:37:39 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && is_in_base(str[i], base) != -1)
	{
		printf("%d\n", is_in_base(str[i], base));
		res = res * str_len(base) + is_in_base(str[i], base);
		i++;
	}
	return (res * sign);
}

int main(int ac, char **av)
{
	printf("%d", ft_atoi_base(av[1], av[2]));
}
