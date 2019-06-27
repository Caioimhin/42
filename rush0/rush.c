/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:52:42 by kparis            #+#    #+#             */
/*   Updated: 2019/06/08 14:59:11 by kparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_fl(int x, int y)
{
	if (x == 1)
		printf("/\n");
	else if (x == 2)
		printf("/\\\n");
	else
	{
		int i = x - 2;
		
		printf("/");
		while (i != 0)
		{
			printf("*");
			i --;
		}
		printf("\\\n");
	}
}

void	print_ll(int x, int y)
{
	if (x == 1)
			printf("\\");
		else if (x == 2)
			printf("\\/\n");
		else
		{
			int i = x - 2;
			
			printf("\\");
			while (i != 0)
			{
				printf("*");
				i --;
			}
			printf("/\n");
		}
}
void	print_mid(int x, int y)
{
	if (x == 1)
		printf("*\n");
	if (x == 2)
		printf("**\n");
	else
	{
		x = x - 2;
		printf("*");
		while (x != 0)
		{
			printf(" ");
			x--;
		}
		printf("*\n");
	}
}

void	rush(int x, int y)
{
	print_fl(x, y);
	if (y > 2)
	{
		while (y != 2)
		{
			print_mid(x, y);
			y--;
		}
	}
	if (y > 1)
		print_ll(x, y);
}

int		main(void)
{
	rush(1, 10);
	return (0);
}
