/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:32:57 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/05 14:31:45 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_value(t_pile *src)
{
	int	smallest;
	int	i;

	i = 0;
	smallest = src->pile[0][0];
	while (i < src->size)
	{
		if (src->pile[0][i] < smallest)
			smallest = src->pile[0][i];
		i++;
	}
	return (smallest);
}

static void	push_back_ends(t_pile *a, t_pile *b)
{
	if (b->pile[0][0] < a->pile[0][0])
		push(b, a, 'a');
	else
	{
		push(b, a, 'a');
		rotate(a, 'a');
	}
	push(b, a, 'a');
	if (value_at_idx(a, 0) != smallest_value(a))
		rotate(a, 'a');
}

void	sort_5(t_pile *a, t_pile *b)
{
	int	*o_tab;
	int	smallest;
	int	biggest;

	smallest = smallest_value(a);
	biggest = find_biggest(a);
	while (a->size != 3)
	{
		if (a->pile[0][0] == smallest
			|| a->pile[0][0] == biggest)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	o_tab = save_pile(a);
	if (o_tab == NULL)
		return ;
	if (check_if_sorted(a->pile[0], a->size) == -1)
		sort_3(a, o_tab);
	push_back_ends(a, b);
	free(o_tab);
}
