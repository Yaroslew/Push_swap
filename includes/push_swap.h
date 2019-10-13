/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:33:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/13 11:37:02 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

typedef struct s_nod
{
	int			data;
	struct s_nod		*next;
	struct s_nod		*back;
}				t_nod;

typedef struct s_base
{
	t_nod		*head;
	t_nod		*temp;
	int			size_stek_a;
	int			size_stek_b;

}				t_base;


t_base	*init_base();

void	check_str(char **str, int size, t_base *base);
void	check_word(char *str, t_base *base);
void	check_duplicate(t_base *base);

void	add_list(t_base *base, char *str, int q);

void	result_ok(int a);

void	write_list(t_base *base);

#endif
