/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:47:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/27 17:37:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_little_tabs(t_pile *a, t_pile *b)
{
	int		*o_tab;

	o_tab = save_pile(a);
	if (o_tab == NULL)
		return ;
	if (a->size < 4)
	{
		sort_3(a, o_tab);
		free(o_tab);
		return ;
	}
	else if (a->size < 6)
	{
		sort_5(a, b);
		free(o_tab);
		return ;
	}
}

void	push_swap(t_pile *a, t_pile *b)
{
	int		*sorted_tab;

	if (check_if_sorted(a->pile[0], a->size) == -1)
	{
		if (a->size < 6)
		{
			push_little_tabs(a, b);
			return ;
		}
		sorted_tab = sort_pile(a);
		if (sorted_tab == NULL)
			return ;
		push_to_b(a, b, sorted_tab, a->size);
		sort_a_left(a);
		push_back(a, b);
		free(sorted_tab);
	}
	else
		return ;
}
