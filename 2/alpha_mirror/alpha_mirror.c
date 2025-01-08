/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:35:13 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/07 12:48:29 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i;
	char letter;
	
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i]>='a' && argv[1][i] <= 'z')
				argv[1][i] =  'z' - (argv[1][i] - 'a');
			if (argv[1][i]>='A' && argv[1][i] <= 'Z')
				argv[1][i] =  'Z' - (argv[1][i] - 'A');
			write (1, &argv[1][i], 1);
			i++;				
		}
	}
	write(1, "\n", 1);
	return (0);
}