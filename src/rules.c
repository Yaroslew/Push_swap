/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 03:15:13 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 23:21:08 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_rule(t_base *base, char *str)
{
	int temp;

	if (ft_strcmp(str, "SA") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		temp = base->temp->data;
		base->temp->data = base->temp->next->data;
		base->temp->next->data = temp;
	}
	if (ft_strcmp(str, "SB") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		temp = base->temp_b->data;
		base->temp_b->data = base->temp_b->next->data;
		base->temp_b->next->data = temp;
	}
	if (ft_strcmp(str, "SS") == 0)
	{
		s_rule(base, "SA");
		s_rule(base, "SB");
	}
}

void	p_rule(t_base *base, char *str)
{
	if (ft_strcmp(str, "PA") == 0)
	{
		if (base->size_stek_b == 0)
			return;
		base->size_stek_b--;
		base->size_stek_a++;
		base->temp = add_list(base->temp);
		base->temp->data = base->temp_b->data;
		base->temp_b = del_list(base->temp_b);

	}
	if (ft_strcmp(str, "PB") == 0)
	{
		if (base->size_stek_a == 0)
			return;
		base->size_stek_b++;
		base->size_stek_a--;
		base->temp_b = add_list(base->temp_b);
		base->temp_b->data = base->temp->data;
		base->temp = del_list(base->temp);
	}
}

void	r_rule(t_base *base, char *str)
{

	if (ft_strcmp(str, "RA") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		base->temp = base->temp->next;
	}
	if (ft_strcmp(str, "RB") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		base->temp_b = base->temp_b->next;
	}
	if (ft_strcmp(str, "RR") == 0)
	{
		r_rule(base, "RA");
		r_rule(base, "RB");
	}
}

void 	rr_rule(t_base *base, char *str)
{
	if (ft_strcmp(str, "RRA") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		base->temp = base->temp->back;
	}
	if (ft_strcmp(str, "RRB") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		base->temp_b = base->temp_b->back;
	}
	if (ft_strcmp(str, "RRR") == 0)
	{
		rr_rule(base, "RRA");
		rr_rule(base, "RRB");
	}
}