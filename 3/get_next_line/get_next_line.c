/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:20:26 by asafrono          #+#    #+#             */
/*   Updated: 2025/02/13 16:19:51 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 	line[70000];
	char 	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		bytes_read;
	char 	*new_line;
	int 	i;

	i = 0;
	buffer_index = 0;
	bytes_read = 0;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return(NULL);
	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			buffer_index = 0;
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				break;
		}
		line[i] = buffer[buffer_index++];
		if (line[i++] == '\n')
			break;
	}
	if (i == 0)
		return(NULL);
	line[i] = '\0';
	new_line = malloc(i + 1);
	if (!new_line)
		return(NULL);
	i = -1;
	while (line[++i])
		new_line[i] = line[i];
	new_line[i] = '\0';
	return(new_line);
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