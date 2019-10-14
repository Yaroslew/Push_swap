/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:34:22 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/14 23:32:23 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_word(char *str, t_base *base)
{
	int q;

	q = 0;
	while (str[q])
	{
		if ((str[q] < '0' || str[q] > '9') && str[q] != ' ' && str[q] != '\t' && str[q] != '-')
			result_ok(-3);
		if ((str[q] == ' ' || str[q] == '\t' || str[q] == '-') && (str[q + 1] >= '0' && str[q + 1] <= '9'))
			init_stek_a(base, str, q);
		else if (q == 0 && (str[q] >= '0' && str[q] <= '9'))
			init_stek_a(base, str, q);
		q++;
	}
}

void	check_str(char **str, int size, t_base *base)
{
	int q;

	q = 1;
	while (q < size)
	{
		check_word(str[q], base);
		q++;
	}
	check_duplicate(base);
	base->temp = base->head;
}

void	check_duplicate(t_base *base)
{
	t_nod	*check;
	t_nod	*finish;
	int 	q;
	int 	r;

	q = 0;
	r = q + 1;
	check = base->head->next;
	finish = base->head;
	while (q < base->size_stek_a)
	{
		while (r < base->size_stek_a)
		{
			if (finish->data == check->data)
				result_ok(-2);
			check = check->next;
			r++;
		}
		q++;
		r = q + 1;
		finish = finish->next;
		check = finish->next->next;
	}
}
