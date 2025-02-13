/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:53 by asafrono          #+#    #+#             */
/*   Updated: 2025/02/13 12:02:47 by asafrono         ###   ########.fr       */
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
int main(void)
{
	char	*line;
	
	line = get_next_line(0);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	return(0);
}