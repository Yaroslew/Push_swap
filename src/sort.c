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
			temp_str = base->res;
			if (q == 0)
			{
				base->res = ft_strjoin(base->res, "PB|");
				p_rule(base, "PB");
			}
			else
			{
				base->res = ft_strjoin(base->res, "RA|");
				r_rule(base, "RA");
			}
			free(temp_str);
			q = -1;
			check = base->temp->back;
		}
		q++;
		check = check->next;
	}
}