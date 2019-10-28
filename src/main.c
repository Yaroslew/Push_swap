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

void	print_list(t_base *base)
{
	int q = 0;
	t_nod *stek_a = base->temp;
	t_nod *stek_b = base->temp_b;

	while (q < base->size_stek_a + base->size_stek_b)
	{
		if (q < base->size_stek_a)
			ft_printf("%d", stek_a->data);
		ft_printf("    |    ");
		if (q < base->size_stek_b)
			ft_printf("%d", stek_b->data);
		ft_printf("\n");
		stek_a = stek_a->next;
		if (stek_b != NULL)
			stek_b = stek_b->next;
		q++;
	}
	ft_printf("=%d  |  %d=\n\n", base->size_stek_a, base->size_stek_b);
}


int	main(int ac, char **av)
{
	t_base *base;

	if (ac < 2)
		return (0);
	base = init_base();
	check_str(av, ac, base);
	write_min_max(base);


	if (check_true_sort(base))
		return (0);
	pre_sort(base);
	sort(base);
	final_sort(base);

	ft_printf("%s", base->res);
	free(base->res);
	free_base(base);


}

