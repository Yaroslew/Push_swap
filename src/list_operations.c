/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:21:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/13 11:55:52 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_list(t_base *base, char *str, int q)
{
	base->size_stek_a++;
	if (!(base->head->next))
	{
		base->head->data = ft_atoi(str + q);
		base->head->next = base->head;
		base->temp = base->head->next;
		return;
	}
	if (!(base->temp->next = malloc(sizeof(t_nod))))
		result_ok(-1);
	base->temp->next->data = ft_atoi(str + q);
	base->temp->next->next = base->head;
	base->temp->next->back = base->temp;
	base->temp = base->temp->next;
}

