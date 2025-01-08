/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:58:10 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 14:07:38 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv)
{
	int i;
	i = 0;


	if (argc == 4)
	{
		while (argv[2][i])
			i++;
		if (i > 1)
		{
			write(1,"\n",1);
			return(0);
		}
		i = 0;		
		while (argv[3][i])
			i++;
		if (i > 1)
		{
			write(1,"\n",1);
			return(0);
		}
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				write(1,&argv[3][0],1);
			else
				write(1,&argv[1][i],1);
			i++;
		}
	}
	write(1,"\n",1);
	return(0);
}