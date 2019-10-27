/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:29:33 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 23:16:50 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_base *init_base()
{
	t_base *base;

	if (!(base = malloc(sizeof(t_base))))
		result_ok(-1);
	if (!(base->head = malloc(sizeof(t_nod))))
		result_ok(-1);

	base->head->next = NULL;
	base->head->back = base->head;
	base->temp = base->head;
	base->temp_b = NULL;
	base->head_b = NULL;
	base->size_stek_a = 0;
	base->size_stek_b = 0;
	base->res = NULL;
	base->save_turns = -1;


	return (base);
}

void	init_stek_a(t_base *base, char *str, int q)
{
	base->size_stek_a++;
	if (!(base->head->next))
	{
		base->head->data = ft_atoi(str + q);
		check_long_int(base->head->data, str, q);
		base->head->next = base->head;
		base->temp = base->head->next;
		base->max = base->head->data;
		base->min = base->head->data;
		return;
	}
	if (!(base->temp->next = malloc(sizeof(t_nod))))
		result_ok(-1);
	base->temp->next->data = ft_atoi(str + q);
	check_long_int(base->temp->next->data, str, q);
	base->temp->next->next = base->head;
	base->temp->next->back = base->temp;
	base->head->back = base->temp->next;
	base->temp = base->temp->next;
}