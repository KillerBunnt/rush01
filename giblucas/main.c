/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckchan <ckchan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:09:16 by ckchan            #+#    #+#             */
/*   Updated: 2024/03/24 18:27:02 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	hardcode(char *s);
int		checkerror(char *z);

int	main(int argv, char **input)
{
	int		a;
	int		b;
	char	*inputstr;

	b = 0;
	a = 0;
	if (argv != 17)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	inputstr = (char *)malloc(16 * sizeof(char));
	while (a < (argv - 1))
	{
		inputstr[a] = *input[a + 1];
		a++;
	}
	inputstr[a] = '\0';
	checkerror(inputstr);
	if (b == 0)
		hardcode(inputstr);
	free(inputstr);
	return (0);
}
