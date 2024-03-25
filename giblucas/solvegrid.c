/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvegrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckchan <ckchan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:09:58 by ckchan            #+#    #+#             */
/*   Updated: 2024/03/24 18:52:49 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_safe(char **grid, int row, int col, int num);

int	is_safe(char **grid, int row, int col, int num)
{
	int	size;
	int	i;
	int	j;

	size = 0;
	i = 0;
	while (i < size)
	{
		if (grid[row][i] == ('0' + num))
			return (0);
		i++;
	}
	j = 0;
	while (j < size)
	{
		if (grid[j][col] == ('0' + num))
			return (0);
		j++;
	}
	return (1);
}

int	solve_grid(char **grid, int row, int col, int *size)
{
	int	num;

	num = 1;
	if (row == *size)
		return (1);
	if (grid[row][col] != '0')
		return (solve_grid(grid, row + (col + 1) / *size, (col + 1) % *size
				, size));
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = '0' + num;
			if (solve_grid(grid, row + (col + 1) / *size, (col + 1) % *size
					, size))
				return (1);
			grid[row][col] = '0';
		}
		num++;
	}
	return (0);
}
