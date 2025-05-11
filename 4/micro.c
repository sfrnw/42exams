/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:32:46 by asafrono          #+#    #+#             */
/*   Updated: 2025/05/11 16:43:08 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

void ft_fatal_error(void)
{
	ft_putstr_fd2("error: fatal", NULL);
	exit(1);
}



int main (int argc, char *argv[], char *env[])
{
	int		i;
	int 	fd[2];
	int 	tmp_fd;
	pid_t 	pid;



	return (0);
}