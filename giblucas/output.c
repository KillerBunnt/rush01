/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckchan <ckchan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:09:33 by ckchan            #+#    #+#             */
/*   Updated: 2024/03/24 18:09:43 by ckchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	output(char **nums)
{
	int		x;
	int		y;
	char	space;
	char	n;

	n = '\n';
	space = ' ';
	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			write(1, &nums[y][x], 1);
			x++;
			if (x != 4)
				write(1, &space, 1);
		}
		x = 0;
		y++;
		write(1, &n, 1);
	}
}
