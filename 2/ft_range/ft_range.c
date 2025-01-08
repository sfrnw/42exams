#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	size = abs((end-start)) + 1;
	res = malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			res[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			res[i] = start;
			start--;
			i++;
		}
	}  
	return(res);
}
// int main()
// {
// 	int *result;
// 	int i;
// 	i = -1;
// 	result = ft_range (1,5);
// 	if (result)
// 	{
// 		while (++i < 5)
// 			printf("%d \n", result[i]);
// 	}
// 	return (0);
// }