#include <stdlib.h>
#include <unistd.h>
void	hardcode(char *s);
int		checkerror(char *z);

int main(int argv, char **input)
{
	int a;
	int b;
	char *inputstr;
	
	a = 0;
	inputstr = (char *)malloc(16 * sizeof(char));
	while (a < (argv - 1))
	{
		inputstr[a] = *input[a+1];
		a++;
	}
	inputstr[a] = '\0';
	checkerror(inputstr);
	if (b == 0)
		hardcode(inputstr);
	free(inputstr);
	return 0;
}
