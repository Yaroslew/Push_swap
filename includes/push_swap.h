/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorlys- <pcorlys-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:33:20 by pcorlys-          #+#    #+#             */
/*   Updated: 2019/10/15 23:21:19 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

// проверка на переполнение инта

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
	t_nod		*head_b;
	t_nod		*temp_b;

	int			size_stek_a;
	int			size_stek_b;

	int			max;
	int			min;
	char		*res;

	int			ind_a;
	int			ind_b;
	int			turns;

}				t_base;


t_base	*init_base();

void	check_str(char **str, int size, t_base *base);
void	check_word(char *str, t_base *base);
void	check_duplicate(t_base *base);

void	init_stek_a(t_base *base, char *str, int q);
void	write_min_max(t_base *base);
void	write_list(t_base *base);

void	result_ok(int a);

t_nod	*add_list(t_nod *now);
t_nod	*del_list(t_nod *nows);

void	s_rule(t_base *base, char *str);
void	p_rule(t_base *base, char *str);
void	r_rule(t_base *base, char *str);
void 	rr_rule(t_base *base, char *str);

// sort
void	start(t_base *base);
void	write_instruction_start(t_base *base);
void	start_sort(t_base *base);


void	print_list(t_base *base);

#endif
