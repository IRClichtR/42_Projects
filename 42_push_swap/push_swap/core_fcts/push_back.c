/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:56:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:59:00 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	loop_push(t_pile *a, t_pile *b)
{
	int		idx_a;
	int		idx_b;

	while (b->size != 0)
	{
		idx_b = select_idxb(a, b);
		idx_a = find_next_idx(a, b->pile[0][idx_b]);
		do_best_push(a, b, idx_a, idx_b);
	}
}

void	push_back(t_pile *a, t_pile *b)
{
	int		smallest;

	loop_push(a, b);
	smallest = find_smallest(a);
	if (ft_strncmp(select_move(a, smallest), "rot", 3) == 0)
		loop_ra(a, smallest);
	else
		loop_rra(a, smallest);
}
