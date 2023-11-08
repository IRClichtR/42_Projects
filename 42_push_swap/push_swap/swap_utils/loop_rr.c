/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:59:20 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/21 11:16:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	loop_rr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int		smallest;

	if (is_bigger(idx_a, idx_b) == 1)
		smallest = idx_b;
	else
		smallest = idx_a;
	if (smallest == 0 || idx_a > a->size - 1 || idx_b > b->size - 1)
		return ;
	while (smallest != 0)
	{
		rotate_2(a, b);
		smallest--;
	}
}
