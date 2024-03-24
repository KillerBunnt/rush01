#include <unistd.h>
#include <stdlib.h>

void	output(char **nums);
void	firstline(char *outstr, char *s, int *a);
int		secondline(char *outstr, char *s, int *a);
int		thirdline(char *outstr, char *s, int *a);
int		lastline(char *outstr, char *s, int *a);
int		solve_grid(char **grid, int row, int col, int *size);
void	matrix(char *s);
void	convert(char *s, char **input, int *size);
void	hardcode(char *s)
{
	int		a;
	int		b;
	char	*outstr;

	outstr = (char *)malloc(16 * sizeof(char));
	a = 0;
	b = 0;
	while (a < 4)
		firstline(outstr, s, &a);
	while (a < 8 && a >= 4 && b != 1)
		b = secondline(outstr, s, &a);
	while (a < 12 && a >= 8 && b != 1)
		b = thirdline(outstr, s, &a);
	while (a < 16 && a >= 12 && b != 1)
		b = lastline(outstr, s, &a);
	if (b == 1)
		return ;
	matrix(outstr);
	free(outstr);
}

void	firstline(char *outstr, char *s, int *a)
{
	if (s[*a] == '1')
		outstr[*a] = '4';
	else if (s[*a] == '4')
	{
		outstr[*a] = '1';
		outstr[(*a + 4)] = '2';
		outstr[(*a + 8)] = '3';
		outstr[(*a + 12)] = '4';
	}
	*a = *a + 1;
}

int	secondline(char *outstr, char *s, int *a)
{
	if (s[*a] == '1' && s[*a - 4] != '1')
		outstr[*a + 8] = '4';
	else if (s[*a] == '4' && s[*a - 4] != '4')
	{
		outstr[*a + 8] = '1';
		outstr[(*a + 4)] = '2';
		outstr[*a] = '3';
		outstr[(*a - 4)] = '4';
	}
	else if (s[*a] != '2' && s[*a] != '3')
	{
		write(1, "ERRO1", 5);
		return (1);
	}
	*a = *a + 1;
	return (0);
}

int	thirdline(char *outstr, char *s, int *a)
{
	if (s[*a] == '1')
	{
		if (!(*a == 8 && s[0] == '4') || !(*a == 11 && s[4] == '4'))
			outstr[*a - 8 + (3 * (*a % 8))] = '4';
	}
	else if (s[*a] == '4')
	{
		if (!(*a == 8 && s[3] == '1') || !(*a == 11 && s[7] == '1'))
		{
			outstr[*a - 8 + (3 * (*a % 8))] = '1';
			outstr[*a - 7 + (3 * (*a % 8))] = '2';
			outstr[*a - 6 + (3 * (*a % 8))] = '3';
			outstr[*a - 5 + (3 * (*a % 8))] = '4';
		}
	}
	else if (s[*a] != '2' && s[*a] != '3')
	{
		write(1, "ERRO2", 5);
		return (1);
	}
	*a = *a + 1;
	return (0);
}

int	lastline(char *outstr, char *s, int *a)
{
	if (s[*a] == '1')
	{
		if ((*a == 12 && s[3] != '4') || (*a == 15 && s[7] != '4'))
			outstr[*a - 9 + (3 * (*a % 12))] = '4';
	}
	else if (s[*a] == '4')
	{
		if ((*a == 12 && s[3] != '1') || (*a == 15 && s[7] != '1'))
		{
			outstr[*a - 9 + (3 * (*a % 12))] = '1';
			outstr[*a - 10 + (3 * (*a % 12))] = '2';
			outstr[*a - 11 + (3 * (*a % 12))] = '3';
			outstr[*a - 12 + (3 * (*a % 12))] = '4';
		}
	}
	else if (s[*a] != '2' && s[*a] != '3')
	{
		write(1, "ERRO3", 5);
		return (1);
	}
	*a = *a + 1;
	return (0);
}

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
			if (s[a] >= '1' && s[a] <= '4')
				input[i][j] = s[a];
			else
				input[i][j] = '0';
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
		write(1,"no solution found", 17);
		return;
	}
}
