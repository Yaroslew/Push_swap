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

#include "push_swap.h"

static void	save_temp_result(t_base *base)
{
	base->save_turns = base->count_turns;
	if (base->save_rules)
		free(base->save_rules);
	base->save_rules = base->buf_rules;
	base->buf_rules = NULL;
}

static int	delta(t_base *base, int ex, int stek)
{
	int		up;
	int		down;

	up = ex;
	if (stek == 1)
		down = base->size_stek_a - ex;
	else
		down = base->size_stek_b - ex;
	if (down < up)
		return (down * -1);
	else
		return (ex);
}

static int	check_position(t_base *base, int a, int b)
{
	t_nod	*check_a;
	t_nod	*check_b;

	check_a = base->temp;
	check_b = base->temp_b;
	while (a > 0)
	{
		check_a = check_a->next;
		a--;
	}
	while (b > 0)
	{
		check_b = check_b->next;
		b--;
	}
	if (check_b->data > check_a->back->data && check_b->data < check_a->data)
		return (1);
	else
		return (0);
}

void		count_turns(t_base *base, int a, int b)
{
	if (check_position(base, a, b) == 0)
		return ;
	base->delta_a = delta(base, a, 1);
	base->delta_b = delta(base, b, 2);
	if (base->delta_a < 0 && base->delta_b < 0 && base->size_stek_b > 1)
		step_down(base);
	if (base->delta_a > 0 && base->delta_b > 0 && base->size_stek_b > 1)
		step_up(base);
	if (base->delta_a != 0 && base->delta_a != base->size_stek_a)
		step_alone_a(base);
	if (base->delta_b != 0 && base->delta_b != base->size_stek_b)
		step_alone_b(base);
	if (base->count_turns < base->save_turns || base->save_turns == -1)
		save_temp_result(base);
	else
	{
		free(base->buf_rules);
		base->buf_rules = NULL;
	}
	base->count_turns = 0;
}
