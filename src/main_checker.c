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

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_base	*base;

	if (ac < 2)
		show_mess(1);
	base = init_base();
	check_str(av, ac, base);
	gnl(base);
	if (check_true_sort(base) && base->size_stek_b == 0)
		result_ok(1);
	else
		result_ok(2);
	free_base(base);
}
