/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:33:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 23:21:19 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		pre_sort_stek_a(t_base *base)
{
	t_nod *check;

	check = base->temp;
	if (check->data < check->next->data && check->next->data < check->back->data)
		return;
	if (check->data < check->next->data && check->next->data > check->back->data && check->data < check->back->data)
	{
		s_rule(base, "sa");
		r_rule(base, "ra");
		base->res = strjoin_my(base->res, "sa\nra\n");
		return;
	}
	if (check->data < check->next->data && check->next->data > check->back->data)
	{
		rr_rule(base, "rra");
		base->res = strjoin_my(base->res, "rra\n");
		return;
	}
	if (check->data > check->next->data && check->next->data < check->back->data && check->data < check->back->data)
	{
		s_rule(base, "sa");
		base->res = strjoin_my(base->res, "sa\n");
		return;
	}
	if (check->data > check->next->data && check->next->data < check->back->data)
	{
		r_rule(base, "ra");
		base->res = strjoin_my(base->res, "ra\n");
		return;
	}
	if (check->data > check->next->data && check->next->data > check->back->data)
	{
		s_rule(base, "sa");
		r_rule(base, "ra");
		r_rule(base, "ra");
		base->res = strjoin_my(base->res, "sa\nra\nra\n");
		return;
	}
}

void	pre_sort(t_base *base)
{
	int q;

	q = 0;
	base->min = base->head->data;
	base->max = base->min;
	while (q < base->size_stek_a)
	{
		base->head = base->head->next;
		if (base->head->data < base->min)
			base->min = base->head->data;
		if (base->head->data > base->max)
			base->max = base->head->data;
		q++;
	}
	write_instruction_start(base);
	pre_sort_stek_a(base);
}

void	write_instruction_start(t_base *base)
{
	int q;
	t_nod	*check;

	q = 0;
	check = base->temp;
	while (q < base->size_stek_a && base->size_stek_a > 3)
	{
		if ((check->data != base->min) && (check->data != base->max))
		{
			if (q == 0)
			{
				base->res = strjoin_my(base->res, "pb\n");
				p_rule(base, "pb");
			}
			else
			{
				base->res = strjoin_my(base->res, "ra\n");
				r_rule(base, "ra");
			}
			q = -1;
			check = base->temp->back;
		}
		q++;
		check = check->next;
	}
	//ft_printf("===%s\n\n\n", base->res);
}
