/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:29:33 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/13 09:14:45 by pcorlys-         ###   ########.fr       */
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
	base->size_stek_a = 0;
	base->size_stek_b = 0;

	return (base);
}
