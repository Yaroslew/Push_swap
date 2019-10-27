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

void	step_down(t_base *base)
{
	base->delta_a *= -1;
	base->delta_b *= -1;
	while (base->delta_a < base->size_stek_a && base->delta_b < base->size_stek_b)
	{
		base->delta_a++;
		base->delta_b++;
		base->count_turns++;
		base->buf_rules = strjoin_my(base->buf_rules, "rrr\n");
	}

	if (base->delta_a == base->size_stek_a)
		base->delta_a = 0;
	if (base->delta_b == base->size_stek_b)
		base->delta_b = 0;
	base->delta_a *= -1;
	base->delta_b *= -1;
}

void	step_up(t_base *base)
{
	while (base->delta_a > 0 && base->delta_b > 0)
	{
		base->delta_a--;
		base->delta_b--;
		base->count_turns++;
		base->buf_rules = strjoin_my(base->buf_rules, "rr\n");
	}
}

void	step_alone_a(t_base *base)
{
	if (base->delta_a < 0)
	{
		base->delta_a *= -1;
		while (base->delta_a < base->size_stek_a - 1)
		{
			base->delta_a++;
			base->count_turns++;
			base->buf_rules = strjoin_my(base->buf_rules, "rra\n");
		}
	}
	else
	{
		while (base->delta_a > 0)
		{
			base->delta_a--;
			base->count_turns++;
			base->buf_rules = strjoin_my(base->buf_rules, "ra\n");
		}
	}
}

void	step_alone_b(t_base *base)
{
	if (base->delta_b < 0)
	{
		base->delta_b *= -1;
		while (base->delta_b < base->size_stek_b)
		{
			base->delta_b++;
			base->count_turns++;
			base->buf_rules = strjoin_my(base->buf_rules, "rrb\n");
		}
	}
	else
	{
		while (base->delta_b > 0)
		{
			base->delta_b--;
			base->count_turns++;
			base->buf_rules = strjoin_my(base->buf_rules, "rb\n");
		}
	}
}

