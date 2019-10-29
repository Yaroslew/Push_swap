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

void	free_base(t_base *base)
{
	int	q;

	q = 0;
	free(base->temp_b);
	base->temp_b = NULL;
	while (q < base->size_stek_a)
	{
		base->head = base->temp->next;
		free(base->temp);
		base->temp = base->head;
		q++;
	}
	free(base);
}
