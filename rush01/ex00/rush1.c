/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:10:34 by kparis            #+#    #+#             */
/*   Updated: 2019/06/16 22:22:17 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_tab[4][4];
int		g_res[4][4];

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	init_res(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			g_res[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	show_res(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			ft_putchar(g_res[i][j] + 48);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int		check_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '4') || str[i] == ' ')
			i++;
		else
		{
			ft_putstr("Error\n");
			return (1);
		}
	}
	if (i != 31)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int		check_error2(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_tab[0][i] + g_tab[1][i] > 101)
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (g_tab[2][i] + g_tab[3][i] > 101)
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	get_args(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (j < 4 && str[i])
		{
			while (k < 4 && str[i])
			{
				if (str[i] == ' ')
					i++;
				g_tab[j][k] = str[i];
				k++;
				i++;
			}
			k = 0;
			j++;
			i++;
		}
		i++;
	}
}

void	complete_col(char c, int j)
{
	int i;
	int n;
	int k;

	i = 0;
	n = 4;
	k = 1;
	while (i < 4)
	{
		if (c == '+')
			g_res[i][j] = k;
		else if (c == '-')
			g_res[i][j] = n;
		else if (c == '*')
			g_res[j][i] = k;
		else if (c == '/')
			g_res[j][i] = n;
		i++;
		k++;
		n--;
	}
}

void	fill_blanks(void)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (g_tab[0][j] == '4' && g_tab[1][j] == '1')
			complete_col('+', j);
		else if (g_tab[0][j] == '1' && g_tab[1][j] == '4')
			complete_col('-', j);
		j++;
	}
	j = 0;
	while (j < 4)
	{
		if (g_tab[2][j] == '4' && g_tab[3][j] == '1')
			complete_col('*', j);
		else if (g_tab[2][j] == '1' && g_tab[3][j] == '4')
			complete_col('/', j);
		j++;
	}
}

void	fill_last_col(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (g_res[i][j] == 0)
			{
				if (i < 2 && g_tab[i][j] == '1')
				{
					if (i == 0)
						g_res[i][j] = 4;
					if (i == 1)
						g_res[i + 2][j] = 4;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		check_col(int val, int j)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_res[i][j] == val)
			return (0);
		i++;
	}
	return (1);
}

int		check_line(int val, int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (g_res[i][j] == val)
			return (0);
		j++;
	}
	return (1);
}

int		check_view_up_down(void)
{
	int val;
	int j;
	int i;
	int view;
	int x;

	i = 0;
	while (i < 2)
	{
		view = 1;
		x = 0;
		while (j < 4)
		{
			val = g_tab[i][j];
			while (x < 3)
			{
				if (g_res[i][x] < g_res[i][x + 1])
					view++;
				x++;
			}
			j++;
			x = 0;
		}
		if (val != view)
			return (1);
		i++;
		j = 0;
	}
	return (0);
}

int		check_view_left_right(void)
{
	int val;
	int j;
	int i;
	int view;
	int x;

	i = 2;
	while (i < 4)
	{
		view = 1;
		x = 0;
		while (j < 4)
		{
			val = g_tab[i][j];
			while (x < 3)
			{
				if (g_res[i][x] < g_res[i][x + 1])
					view++;
				x++;
			}
			j++;
			x = 0;
		}
		if (val != view)
			return (1);
		i++;
		j = 0;
	}
	return (0);
}

int		backtracking(int pos)
{
	int		i;
	int		j;
	int		val;

	i = pos / 4;
	j = pos % 4;
	if (pos == 4 * 4)
		return (1);
	if (g_res[i][j] != 0)
		return (backtracking(pos + 1));
	val = 0;
	while (val <= 4)
	{
		if ((check_line(val, i) && check_col(val, j)) &&
				(check_view_up_down() && check_view_left_right()))
		{
			g_res[i][j] = val;
			if (backtracking(pos + 1))
				return (1);
		}
		val++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	init_res();
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	get_args(argv[1]);
	if (check_error(argv[1]) == 1)
		return (1);
	if (check_error2() == 1)
		return (1);
	fill_blanks();
	fill_last_col();
	backtracking(0);
	show_res();
	return (0);
}
