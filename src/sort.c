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

void	release_step(t_base *base)
{
	int q;
	int n;

	q = -1;
	n = 0;
	base->res = strjoin_my(base->res, base->save_rules);
	ft_printf("%s   |  %d\n", base->save_rules, base->save_turns);

	while(base->save_rules[q])
	{
		if (base->save_rules[q] == '\n')
		{
			if (q - n == 4)
				release_rule(base, base->save_rules[q - 1], 4);
			else
				release_rule(base, base->save_rules[q - 1], 3);
		}
		q++;
		n = q;
	}
	free(base->save_rules);
	base->save_rules = NULL;
}