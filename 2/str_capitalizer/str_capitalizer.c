/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:49:11 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:57 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	int i;
	int j;

	j = 1;
	if (argc >= 2)
	{
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				if ((argv[j][i-1] == ' ' || argv[j][i-1] == '\t') || (i == 0)) 
				{
					if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
						argv[j][i] -= 32;
				}
				else if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
					argv[j][i] += 32;
				write(1, &argv[j][i],1);
				i++;
			}
			write(1,"\n",1);
			j++;
		}
	}
	else
		write(1,"\n",1);
	return(0);
}