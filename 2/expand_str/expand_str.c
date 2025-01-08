#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	int space;
	i = 0;
	space = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] != ' ')
				write(1, &argv[1][i],1);
			while (argv[1][i] == ' ' && argv[1][i+1] != '\0' && i != 0)
			{
				space = 1;
				i++;
			}
			if (space == 1 && argv[1][i+1] != '\0')
			{
				write(1, "   ", 3);
				space = 0;
				i--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}