/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_idxb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:39 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:21:50 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

static int	calculate_cost(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int		cost;
	char	*move_a;
	char	*move_b;

	cost = 0;
	move_a = select_move(a, idx_a);
	move_b = select_move(b, idx_b);
	if (idx_a == 0 && idx_b == 0)
		return (0);
	else if (ft_strncmp(move_a, "rot", 3) == 0
		&& ft_strncmp(move_b, "rot", 3) == 0)
		cost = find_bigger(idx_a, idx_b);
	else if (ft_strncmp(move_a, "rev", 3) == 0
		&& ft_strncmp(move_b, "rev", 3) == 0)
		cost = b->size - find_bigger(idx_a, idx_b);
	else if (ft_strncmp(move_a, "rot", 3) != ft_strncmp(move_b, "rot", 3))
		cost = idx_a + idx_b;
	return (cost);
}

int	select_idxb(t_pile *a, t_pile *b)
{
	int	ib;
	int	i;
	int	cost_i;
	int	cost_b;

	ib = 0;
	i = 0;
	while (i < b->size)
	{
		cost_i = calculate_cost(a, b, find_next_idx(a, b->pile[0][i]), ib);
		cost_b = calculate_cost(a, b, find_next_idx(a, b->pile[0][ib]), ib);
		if (cost_i < cost_b)
			ib = i;
		i++;
	}
	return (ib);
}
