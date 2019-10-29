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
		return (0);
	base = init_base();
	check_str(av, ac, base);
	write_min_max(base);
	if (check_true_sort(base))
	{
		free_base(base);
		return (0);
	}
	pre_sort(base);
	sort(base);
	final_sort(base);
	ft_printf("%s", base->res);
	free(base->res);
	free_base(base);
}
