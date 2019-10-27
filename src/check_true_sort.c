/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:32:25 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 22:07:14 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_true_sort(t_base *base)
{
	int q;
	t_nod	*check;

	q = 0;
	check = base->temp;
	while (q < base->size_stek_a - 1)
	{
		if (check->data > check->next->data)
			return;
		check = check->next;
		q++;
	}
	result_ok(1);
}