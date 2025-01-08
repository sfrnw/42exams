#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_atoi_base(char *str, int str_base)
{
	int sign;
	long long result;
	int i;
	int digit;
	sign = 1;
	result = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else
			break;
		if (digit >= str_base)
			break;
		result = result*str_base + digit;
		i++;
	}
	return(result*sign);
}


