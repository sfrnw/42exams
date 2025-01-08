#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
	int number;
	int i;
	int k;
	i = 2;
	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		while (i <= number)
		{
			if ((number % i) == 0)
			{
				printf("%d", i);
				if (i < number)
					printf("*");
				number /= i;
				i = 2;
			}
			i++;
		}
	}
	printf("\n");
}
