#include <stdlib.h>
#include <unistd.h>

void	output(char **nums);
int		solve_grid(char **grid, int row, int col, int *size);
void	convert(char *s, char **input, int *size);

void	matrix(char *s)
{
	char	**input;
	int		i;
	int		size;
	size = 4;
	input = malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		input[i] = malloc(sizeof(char) * size);
		i++;
	}
	convert(s, input, &size);
}

void	convert(char *s, char **input, int *size)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while (i < *size)
	{
		while (j < *size)
		{
			input[i][j] = (s[a] >= '1' && s[a] <= '4') ? s[a] : '0';
			j++;
			a++;
		}
		j = 0;
		i++;
	}
	if (solve_grid(input, 0, 0, size))
		output(input);
	else
	{
		write(1,"Error\n", 6);
		return;
	}
}
