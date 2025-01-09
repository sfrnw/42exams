/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:03:08 by asafrono          #+#    #+#             */
/*   Updated: 2025/01/08 16:21:29 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;

	if (begin_list == NULL || *begin_list == NULL)
		return;
	list = *begin_list;

	if(cmp(list->data, data_ref) == 0)
	{
		*begin_list = list->next;
		free(list);
		ft_list_remove_if(begin_list,data_ref, cmp);
	}
	list = *begin_list;
	ft_list_remove_if(list->next,data_ref, cmp);
}