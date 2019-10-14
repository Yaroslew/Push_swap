/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:21:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 02:02:34 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_nod	*add_list(t_nod *now)
{
	t_nod	*back_old;

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
	t_nod	*next_old;

	next_old = now->next;
	now->back->next = now->next;
	next_old->back = now->back;
	now = next_old;
	now->next = NULL;
	now->back = NULL;
	free(now);
	return (now);
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

