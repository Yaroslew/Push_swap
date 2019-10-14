/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:21:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/14 02:56:59 by pcorlys-         ###   ########.fr       */
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
		base->max = base->head->data;
		base->min = base->head->data;
		return;
	}
	if (!(base->temp->next = malloc(sizeof(t_nod))))
		result_ok(-1);
	base->temp->next->data = ft_atoi(str + q);
	base->temp->next->next = base->head;
	base->temp->next->back = base->temp;
	base->temp = base->temp->next;
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

void	write_list(t_base *base)
{
	t_nod *check;

	int q = 0;
	check = base->head;
	while (q < base->size_stek_a)
	{
		ft_printf("%d\n", check->data);
		check = check->next;
		q++;
	}
	ft_printf("size=%d\n", base->size_stek_a);
}