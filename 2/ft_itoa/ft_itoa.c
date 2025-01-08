/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:56:43 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:31 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	len_nbr(int n)
{
	int length;
	length = 0;
	if (n < 0)
	{
		length ++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int nbr)
{
	int l;
	char *str;
	int length;

	if (nbr == 0)
		return ("0\0");
	if (nbr == -2147483648)
		return ("-2147483648\0");
	length = len_nbr(nbr);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return(NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[--length] = '\0';
	while (nbr)
	{
		str[length] = (nbr % 10) +'0';
		nbr /= 10;
		length--;
	}
	return (str);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// }