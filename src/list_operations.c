/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:21:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 23:20:00 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_nod	*add_list(t_nod *now)
{
	t_nod	*back_old;

	if (now == NULL)
	{
		if (!(back_old = malloc(sizeof(t_nod))))
			result_ok(-1);
		back_old->next = back_old;
		back_old->back = back_old;
		return (back_old);
	}
	back_old = now->back;
	if (!(now->back = malloc(sizeof(t_nod))))
		result_ok(-1);
	now->back->back = back_old;
	now->back->next = now;
	back_old->next = now->back;
	return (now->back);
}

t_nod	*del_list(t_nod *now)
{
	t_nod	*del;
	t_nod	*save_next;

	del = now;
	save_next = now->next;

	now->next->back = now->back;
	now->back->next = save_next;
	free(del);

	return (save_next);
}

void	write_min_max(t_base *base)
{
	int q;
	t_nod	*check;

	q = 0;
	check = base->head;
	while (q < base->size_stek_a)
	{
		if (check->data > base->max)
			base->max = check->data;
		if (check->data < base->min)
			base->min = check->data;
		check = check->next;
		q++;
	}
}

