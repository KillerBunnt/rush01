/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckchan <ckchan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:09:02 by ckchan            #+#    #+#             */
/*   Updated: 2024/03/24 18:09:11 by ckchan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkerror(char *s)
{
	int	a;

	a = 0;
	while (a < 16)
	{
		while (a < 4 || (a > 7 && a < 16))
		{
			if ((s[a] == '1' && s[a + 4] == '1')
				|| (s[a] == '2' && s[a + 4] == '4'))
				return (0);
			else if ((s[a] == '4' && s[a + 4] == '2')
				|| (s[a] == '3' && s[a + 4] == '3'))
				return (0);
			else if ((s[a] == '3' && s[a + 4] == '4')
				|| (s[a] == '4' && s[a + 4] == '3'))
				return (0);
			else if (s[a] == '4' && s[a + 4] == '4')
				return (0);
			a++;
		}
		a = a + 4;
	}
	return (1);
}