/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:49:46 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 17:07:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static void	rev_rotation(t_pile *pile)
{
	int	last;
	int	i;

	if (pile->size < 2)
		return ;
	last = find_last_idx(pile);
	i = last - 1;
	while (last != 0)
	{
		ft_swap(&pile->pile[0][last], &pile->pile[0][i]);
		i--;
		last--;
	}
}

void	rev_rotate_2(t_pile *a, t_pile *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rev_rotation(a);
	rev_rotation(b);
	ft_printf("rrr\n");
}
