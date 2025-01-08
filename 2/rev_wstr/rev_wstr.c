/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:22 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 14:56:40 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	int i;
	int start;
	int end;
	
	i = 0;


	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		while (i >= 0)
		{	
			while (i >=0 && (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0'))
				i--;
			end = i + 1;
			while(i >=0 && argv[1][i]!= ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			while(start < end)
			{
				write(1,&argv[1][start],1);
				start++;
			}
			if (i > 0)
				write(1," ",1);
		}
	}
	write(1,"\n",1);
	return(0);
}