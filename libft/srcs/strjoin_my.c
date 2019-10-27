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

/*
 * соединяет первую и вторую строку, зафришив предыдущие.
 * Возвращает NULL, если обе строки NULL.
 *
 */

#include "../includes/libft.h"

static int	sum_len(char *str)
{
	int q;

	q = 0;
	if (str == NULL)
		return (0);
	q = ft_strlen(str);
	return (q);
}

char	*strjoin_my(char *first, char *second)
{
	int q;
	int r;
	char *res;
	int sum;

	q = 0;
	r = 0;
	//ft_printf(" %s %s     \n-----\n ", first, second);
	if (!first && !second)
		return (NULL);
	sum = sum_len(first) + sum_len(second);
	if (!(res = malloc(sizeof(char) * (sum + 1))))
		return (NULL);
	if (first != NULL)
	{
		while (first[q])
		{
			res[r] = first[q];
			q++;
			r++;
		}
		q = 0;
		free(first);
	}

	if (second != NULL)
	{
		while (second[q])
		{
			res[r] = second[q];
			q++;
			r++;
		}
	}

	res[r] = '\0';
	//ft_printf(" %s  \n\n======================\n\n", res);
	return (res);
}