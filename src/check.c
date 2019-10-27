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

void	check_duplicate(t_base *base) {
	t_nod *check;
	int q;
	int r;
	t_nod *sum;
	int pizdec;

	q = 0;
	sum = base->temp;
	while (r < base->size_stek_a) {
		pizdec = 0;
		check = base->temp;
		while (q < base->size_stek_a) {
			if (sum->data == check->data)
				pizdec++;
			q++;
			check = check->next;
		}
		sum = sum->next;
		q = 0;
		if (pizdec > 1)
			result_ok(-2);
		r++;
	}
}

void	check_long_int(int data, char *str, int q)
{
	char *check;
	int	r;

	r = 0;
	check = ft_itoa(data);
	while (check[r])
	{
		if (check[r] != str[q])
			result_ok(-1);
		r++;
		q++;
	}
}