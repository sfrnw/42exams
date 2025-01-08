/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:58:01 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/07 14:15:28 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int     *ft_rrange(int start, int end)
{
	int l;
	int *arr;
	int i;

	i = 0;
	l = end - start;
	if (l < 0)
		l = -l;
	l++;
	arr = (int *)malloc(sizeof(int)*l);
	while (i < l)
	{
		if (start < end)
		{
			arr[i] = end;
			end--;
			
		}
		else
		{
			arr[i] = end;
			end++;
		}
		i++;
	}
	return (arr);		
}
// int main (int argc, char **argv)
// {
// 	int l;
// 	int start;
// 	int end;
// 	int *arr;

// 	if (argc == 3)
// 	{
// 		start = atoi(argv[1]);
// 		end = atoi(argv[2]);
		
// 		l = end - start;
// 		if (l < 0)
// 			l = -l;
// 		l++;
// 		arr = ft_rrange(start, end);
// 		while (l)
// 		{
// 			printf("%d ", *arr++);
// 			l--;
// 		}
// 	}
// 	return(0);
// }