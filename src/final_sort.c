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

static void	final_sort_norm(t_base *base, int q)
{
	while (q < base->size_stek_a)
	{
		base->res = strjoin_my(base->res, "rra\n");
		rr_rule(base, "rra");
		q++;
	}
}

void		final_sort(t_base *base)
{
	int		q;
	t_nod	*check;

	q = 0;
	check = base->temp;
	while (check->data != base->min)
	{
		q++;
		check = check->next;
	}
	if (q < base->size_stek_a / 2)
	{
		while (q > 0)
		{
			base->res = strjoin_my(base->res, "ra\n");
			r_rule(base, "ra");
			q--;
		}
	}
	else
		final_sort_norm(base, q);
	base->temp_b = NULL;
}
