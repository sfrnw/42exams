#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	int i;
	int l;

	i = 0;
	l = 0; 
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i]>='a' && argv[1][i]<='z')
			{
				l = argv[1][i] - 'a' + 1;
				while (l > 0)
				{
					write(1, &argv[1][i], 1);
					l--;	
				}
			}
			else if (argv[1][i]>='A' && argv[1][i]<='Z')
			{
				l = argv[1][i] - 'A' + 1;
				while (l > 0)
				{
					write(1, &argv[1][i], 1);
					l--;	
				}
			}
			else 
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}