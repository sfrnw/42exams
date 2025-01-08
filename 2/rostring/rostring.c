/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:26:38 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 13:27:39 by asafrono         ###   ########.fr       */
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
	int start;
	int more_words;

	i = 0;
	if (argc >= 2 && argv[1])
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		start = i;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i++;
		more_words = 0;
		j = i;
		while (argv[1][j])
		{
			if (argv[1][j] != ' ')
			{
				more_words = 1;
				break;
			}
			j++;
		}
		if (more_words)
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			while (argv[1][i])
			{
				if (argv[1][i] != ' ' && argv[1][i] != '\t')
					write(1, &argv[1][i],1);
				else if (argv[1][i+1] && argv[1][i+1] != ' ' && argv[1][i+1] != '\t')
					write(1," ",1);
				i++;		
			}
			write(1," ",1);
		}
		while (argv[1][start] && argv[1][start] != ' ')
		{
			write(1, &argv[1][start],1);
			start++;
		}
	}
	write(1,"\n",1);
	return(0);
}