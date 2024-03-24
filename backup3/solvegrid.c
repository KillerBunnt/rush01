#include <stdio.h>

int	is_safe(char **grid, int row, int col, int num, int *size);

int is_safe(char **grid, int row, int col, int num, int *size)
{
    // Check if the number is already used in the current row
	int	i;
	int	j;
	
	i = 0;
	while (i < *size)
	{
		if (grid[row][i] == ('0' + num))
			return 0;
		i++;
	}
    // Check if the number is already used in the current column
	j = 0;
	while (j < *size)
	{
		if (grid[j][col] == ('0' + num))
			return 0;
		j++;
	}
	return 1;
}

int solve_grid(char **grid, int row, int col, int *size){
	int num;

	num = 1;
    // If we've reached the end of the grid, return success
    if (row == *size)
        return 1;
    // If the cell is already filled, move to the next cell
    if (grid[row][col] != '0')
		return solve_grid(grid, row + (col + 1) / *size, (col + 1) % *size, size);

    // Try placing numbers {1, 2, 3} and backtrack if not possible
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num, size))
		{
			grid[row][col] = '0' + num;
			if (solve_grid(grid, row + (col + 1) / *size, (col + 1) % *size, size))
				return 1; // Success
			grid[row][col] = '0'; // Backtrack
		}
		num++;
	}
	return 0; // No solution found
}
