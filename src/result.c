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

#include "../includes/push_swap.h"

void	result_ok(int a)
{
	if (a == 14)
		ft_printf("Ok\n");
	if (a == 0 || a == -1 || a == -2 || a == -3)
		ft_printf("Error\n");
//	if (a == -1)
//		ft_printf("Malloc\n");
//	if (a == -2)
//		ft_printf("Duplication\n");
//	if (a == -3)
//		ft_printf("---\n");
	exit(0);
}
