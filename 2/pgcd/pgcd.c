
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int num1;
	int num2;
	int i;
	int k;
	int hcd;
	hcd = 1;
	i = 1;
	if (argc == 3)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		if (num1 < num2)
			k = num1;
		else
			k = num2;
		while (i <= k)
		{
			if ((num1 % i == 0) && (num2 % i == 0))
				hcd = i;
			i++;
		}
		printf("%d", hcd);
	}
	printf("\n");
	return (0);
}