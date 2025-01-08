/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:09:21 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/07 15:21:40 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
	int result;
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			result = atoi(argv[1]) + atoi(argv[3]);
		else if (argv[2][0] == '-')
			result = atoi(argv[1]) - atoi(argv[3]);
		else if (argv[2][0] == '/')
			result = atoi(argv[1]) / atoi(argv[3]);
		else if (argv[2][0] == '*')
			result = atoi(argv[1]) * atoi(argv[3]);
		else if (argv[2][0] == '%')
			result = atoi(argv[1]) % atoi(argv[3]);
		printf("%d\n", result);
	}
	else 
		write(1, "\n",1);
	return(0);
}