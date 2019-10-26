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

# include "../includes/push_swap.h"

static void	save_temp_result(t_base *base)
{
	base->save_turns = base->count_turns;
	if (base->save_rules)
		free(base->save_rules);
	base->save_rules = base->buf_rules;
	base->buf_rules = NULL;
}

static int	delta(t_base *base, int ex)
{
	int up;
	int down;

	up = ex;
	down = base->size_stek_a - ex;
	if (down < up)
		return (down * -1);
	else
		return (up);

}

void	count_turns(t_base *base, int a, int b)
{
	base->delta_a = delta(base, a);
	base->delta_b = delta(base, b);
	if (base->delta_a < 0 && base->delta_b < 0)
		step_down(base);
	if (base->delta_a > 0 && base->delta_b > 0)
		step_up(base);
	if (base->delta_a != 0 && base->delta_a != base->size_stek_a)
		step_alone_a(base);
	if (base->delta_b != 0 && base->delta_b != base->size_stek_b)
		step_alone_b(base);

	if (base->count_turns < base->save_turns || base->save_turns == -1)
		save_temp_result(base);
}