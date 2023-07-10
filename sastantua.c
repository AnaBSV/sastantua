/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: login       <login@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:26:30 by ade-sous          #+#    #+#             */
/*   Updated: 2023/07/10 08:26:30 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

void	repeat_char(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

void	print_door(int star, int n, int floor, int floors)
{
	int	door_len;

	door_len = n - !(n % 2);
	repeat_char('*', (star - door_len) / 2);
	if (floor == (floors - door_len / 2) && door_len > 3)
	{
		repeat_char('|', door_len - 2);
		repeat_char('$', 1);
		repeat_char('|', 1);
	}
	else
		repeat_char('|', door_len);
	repeat_char('*', (star - door_len) / 2);
}

void	print_floor(int floor, int increment, int n, int floors)
{
	int	space;
	int	base_len;
	int	star;

	base_len = (floors * 2 - 1) + (n - 1) * (4 * n / 2);
	star = floor * 2 - 1 + increment * 2;
	space = (base_len - star) / 2;
	repeat_char(' ', space);
	repeat_char('/', 1);
	if (floor > floors - n + !(n % 2))
		print_door(star, n, floor, floors);
	else
		repeat_char('*', star);
	repeat_char('\\', 1);
	repeat_char('\n', 1);
}

void	sastantua(int n)
{
	int	floors;
	int	floor;
	int	increment;
	int	bloc_limit;
	int	curr_bloc;

	floor = 1;
	increment = 0;
	curr_bloc = 1;
	bloc_limit = 3;
	floors = n / 2.0 * (3 + n + 2);
	while (floor <= floors)
	{
		if (floor == bloc_limit + 1)
		{	
			curr_bloc++;
			bloc_limit += curr_bloc + 2;
			increment += curr_bloc / 2 + 1;
		}
		print_floor(floor, increment, n, floors);
		floor++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;

	i = 0;
	if (argc == 2)
	{
		n = 0;
		if (argv[1][i] == '+')
			i++;
		while (argv[1][i] != '\0')
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			{
				write(1, "Invalid argument!\n", 18);
				return (1);
			}
			n = n * 10 + argv[1][i++] - '0';
		}
		sastantua(n);
	}
	else
		write(1, "Enter only one argument.\n", 28);
	return (0);
}
