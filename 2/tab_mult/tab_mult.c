/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:26:38 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 12:47:13 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1,&c,1);
}

int main (int argc, char **argv)
{
	int i;
	int num;
	int result;
	
	i = 0;
	num = 0;
	if (argc == 2)
	{
		while (argv[1][i] >='0' && argv[1][i]<='9')
		{
			num = num * 10;
			num += (argv[1][i] - '0');
			i++;
		}
		i = 1;
		while (i <= 9)
		{
			result = i * num;
			ft_putnbr(i);
			write(1," x ",3);
			ft_putnbr(num);
			write(1," = ",3);
			ft_putnbr(result);
			write(1,"\n",1);
			i++;
		}
	}
	else
		write(1,"\n",1);
	return(0);
}