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

void	pre-sort(t_base *base)
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
				base->res = strjoin_my(base->res, "PB\n");
				p_rule(base, "PB");
			}
			else
			{
				base->res = strjoin_my(base->res, "RA\n");
				r_rule(base, "RA");
			}
			q = -1;
			check = base->temp->back;
		}
		q++;
		check = check->next;
	}
}


void	sort(t_base *base)
{
	int ind_a;
	int ind_b;

	ind_a = 0;
	ind_b = 0;
	while (base->size_stek_b > 0)
	{
		base->count_turns = 0;
		base->save_turns = -1;
		while (ind_a < base->size_stek_a)
		{
			while (ind_b < base->size_stek_b)
			{
				count_turns(base, ind_a, ind_b);
				ind_b++;
			}
			ind_a++;
			ind_b = 0;
		}
		ind_a = 0;
		release_step(base);
	}
}

void	release_step(t_base *base)
{
	
}