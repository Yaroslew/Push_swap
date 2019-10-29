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

static void	check_valid_rule(char *line)
{
	if (ft_strcmp(line, "rr") != 0 && ft_strcmp(line, "ra") != 0 &&
	ft_strcmp(line, "rb") != 0 &&
	ft_strcmp(line, "rrr") != 0 && ft_strcmp(line, "rra") != 0 &&
	ft_strcmp(line, "rrb") != 0 &&
	ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0 &&
	ft_strcmp(line, "ss") != 0 &&
	ft_strcmp(line, "pa") != 0 && ft_strcmp(line, "pb") != 0)
		result_ok(0);
}

void		gnl(t_base *base)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "rr") == 0 || ft_strcmp(line, "ra") == 0 ||
		ft_strcmp(line, "rb") == 0)
			r_rule(base, line);
		if (ft_strcmp(line, "rrr") == 0 || ft_strcmp(line, "rra") == 0 ||
		ft_strcmp(line, "rrb") == 0)
			rr_rule(base, line);
		if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 ||
		ft_strcmp(line, "ss") == 0)
			s_rule(base, line);
		if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			p_rule(base, line);
		check_valid_rule(line);
		free(line);
		line = NULL;
	}
}
