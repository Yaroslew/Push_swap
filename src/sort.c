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

static void	release_rule(t_base *base, char sym, int rule)
{
	if (rule == 4)
	{
		if (sym == 'a')
			rr_rule(base, "rra");

		if (sym == 'b')
			rr_rule(base, "rrb");
		if (sym == 'r')
			rr_rule(base, "rrr");
	}
	else
	{
		if (sym == 'a')
			r_rule(base, "ra");
		if (sym == 'b')
			r_rule(base, "rb");
		if (sym == 'r')
			r_rule(base, "rr");
	}
}

static void save_release(t_base *base)
{
	if (base->save_rules)
	{
		base->res = strjoin_my(base->res, base->save_rules);
		free(base->save_rules);
		base->save_rules = NULL;
	}
	base->res = strjoin_my(base->res, "pa\n");
	p_rule(base, "pa");
}

void	release_step(t_base *base)
{
	int q;
	int n;

	q = 0;
	n = 0;
	if (base->save_rules)
	{
		while (base->save_rules[q])
		{
			if (base->save_rules[q] == '\n')
			{
				if (q - n == 3)
					release_rule(base, base->save_rules[q - 1], 4);
				else
					release_rule(base, base->save_rules[q - 1], 3);
				n = q + 1;
			}
			q++;

		}
	}
	save_release(base);
}
