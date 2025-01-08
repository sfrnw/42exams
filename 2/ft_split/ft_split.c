
#include <stdlib.h>
#include <stdio.h>

#define WD_NUM 1000
#define WD_LEN 1000

char	**ft_split(char *str)
{
	char	**arr;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) * WD_NUM);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	j = 0;
	while (*str != '\0')
	{
		if (*str > 32)
		{
			k = 0;
			arr[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (*str > 32)
				arr[j][k++] = *str++;
			arr[j][k] = '\0';
			j++;
		}
		else
			str++;
	}
	arr[j] = 0;
	return (arr);
}
