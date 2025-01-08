/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:09:51 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 12:24:59 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv)
{
	int i;
	int l;

	i = 0;
	l = 0;
	if (argc == 2)
	{
		while (argv[1][l])
			l++;
		l--;
		while (l >=0 && (argv[1][l] == ' '))
			l--;
		i = l;
		while (i >=0 && (argv[1][i] != ' '))
			i--;
		i++;
		while (i <= l)
		{
			write(1, &argv[1][i],1);
			i++;
		}
	}
	write(1,"\n",1);
	return(0);
}