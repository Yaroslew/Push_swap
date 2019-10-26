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

	if (ft_strcmp(str, "sa") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		temp = base->temp->data;
		base->temp->data = base->temp->next->data;
		base->temp->next->data = temp;
	}
	if (ft_strcmp(str, "sb") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		temp = base->temp_b->data;
		base->temp_b->data = base->temp_b->next->data;
		base->temp_b->next->data = temp;
	}
	if (ft_strcmp(str, "ss") == 0)
	{
		s_rule(base, "sa");
		s_rule(base, "sb");
	}
}

void	p_rule(t_base *base, char *str)
{
	if (ft_strcmp(str, "pa") == 0)
	{
		if (base->size_stek_b == 0)
			return;
		base->size_stek_b--;
		base->size_stek_a++;
		base->temp = add_list(base->temp);
		base->temp->data = base->temp_b->data;
		base->temp_b = del_list(base->temp_b);

	}
	if (ft_strcmp(str, "pb") == 0)
	{
		if (base->size_stek_a == 0)
			return;
		base->size_stek_b++;
		base->size_stek_a--;
		if (base->size_stek_b == 1)
			base->temp_b = add_list(NULL);
		else
			base->temp_b = add_list(base->temp_b);

		base->temp_b->data = base->temp->data;
		base->temp = del_list(base->temp);
	}
}

void	r_rule(t_base *base, char *str)
{

	if (ft_strcmp(str, "ra") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		base->temp = base->temp->next;
	}
	if (ft_strcmp(str, "rb") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		base->temp_b = base->temp_b->next;
	}
	if (ft_strcmp(str, "rr") == 0)
	{
		r_rule(base, "ra");
		r_rule(base, "rb");
	}
}

void 	rr_rule(t_base *base, char *str)
{
	if (ft_strcmp(str, "rra") == 0)
	{
		if (base->size_stek_a < 2)
			return;
		base->temp = base->temp->back;
	}
	if (ft_strcmp(str, "rrb") == 0)
	{
		if (base->size_stek_b < 2)
			return;
		base->temp_b = base->temp_b->back;
	}
	if (ft_strcmp(str, "rrr") == 0)
	{
		rr_rule(base, "rra");
		rr_rule(base, "rrb");
	}
}