/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:54 by asafrono          #+#    #+#             */
/*   Updated: 2025/02/13 12:16:44 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	char *word;

	line = malloc(10000);
	word = line;
	while(read(fd, word, 1) > 0 && *word++ != '\n');
	if (word > line)
	{
		*word = 0;
		return (line);
	}
	else 
		return(free(line), NULL);
}