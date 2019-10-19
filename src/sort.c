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

void	start(t_base *base)
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

}

void	write_instruction_start(t_base *base)
{
	int q;
	char *temp_str;
	t_nod	*check;

	q = 0;
	check = base->temp;
	while (q < base->size_stek_a && base->size_stek_a > 3)
	{
		if ((check->data != base->min) && (check->data != base->max))
		{
			if (q == 0)
			{
				base->res = strjoin_my(base->res, "PB|");
				p_rule(base, "PB");
			}
			else
			{
				base->res = strjoin_my(base->res, "RA|");
				r_rule(base, "RA");
			}
			q = -1;
			check = base->temp->back;
		}
		q++;
		check = check->next;
	}
}

void	start_sort(t_base *base)
{
	t_nod *check;

	check = base->temp;
	if (check->data < check->next->data && check->next->data < check->back->data)
		return;
	if (check->data < check->next->data && check->next->data > check->back->data && check->data < check->back->data)
	{
		s_rule(base, "SA");
		r_rule(base, "RA");
		strjoin_my(base->res, "SA|");
		strjoin_my(base->res, "RA|");
		return;
	}
	if (check->data < check->next->data && check->next->data > check->back->data)
	{
		rr_rule(base, "RRA");
		strjoin_my(base->res, "RRA|");
		return;
	}
	if (check->data > check->next->data && check->next->data < check->back->data && check->data < check->back->data)
	{
		s_rule(base, "SA");
		strjoin_my(base->res, "SA|");
		return;
	}
	if (check->data > check->next->data && check->next->data < check->back->data)
	{
		r_rule(base, "RA");
		strjoin_my(base->res, "RA|");
		return;
	}
	if (check->data > check->next->data && check->next->data > check->back->data)
	{
		s_rule(base, "SA");
		strjoin_my(base->res, "SA|");
		r_rule(base, "RA");
		strjoin_my(base->res, "RA|");
		r_rule(base, "RA");
		strjoin_my(base->res, "RA|");
		return;
	}

}

//void	sort(t_base *base)
//{
//	int q;
//	int r;
//
//	q = 0;
//	r = 0;
//	while (r < base->size_stek_a)
//	{
//		while (q < base->size_stek_b)
//		{
//
//		}
//		q = 0;
//		r++;
//	}
//}