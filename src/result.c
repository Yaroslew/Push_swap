/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:48:21 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/13 12:07:02 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	result_ok(int a)
{
	if (a == 1)
		ft_printf("OK\n");
	if (a == 2)
		ft_printf("KO\n");
	if (a == 0 || a == -1 || a == -2 || a == -3)
		ft_printf("Error\n");
	exit(0);
}

void	show_mess(int q)
{
	if (q == 1)
	{
		ft_printf("usage: ./checker [stek a]\n\n");
		ft_printf("instructions for sort:\n");
		ft_printf("sa sb ss -  swap the first 2 elements at the top "
			"(stek a, stek b, stak a and b)\n");
		ft_printf("pa pb - take the first element at the top of b and put it"
			" at the top of a, and vice versa\n");
		ft_printf("ra rb rr - shift up all elements of stack by 1. The first "
			"element becomes the last one\n");
		ft_printf("rra rrb rrr - shift down all elements of stack by 1. The"
			" last element becomes the first one.\n");
	}
	if (q == 2)
		ft_printf("usage: ./push_swap [stek a]\n");
	exit(0);
}
