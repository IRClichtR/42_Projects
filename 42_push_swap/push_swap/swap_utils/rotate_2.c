/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:57:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 20:57:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static void	rotation(t_pile *pile)
{
	int	i;
	int	last;

	if (pile->size < 2)
		return ;
	i = 0;
	last = find_last_idx(pile);
	while (i < last)
	{
		ft_swap(&pile->pile[0][i], &pile->pile[0][i + 1]);
		i++;
	}
}

void	rotate_2(t_pile *a, t_pile *b)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rotation(a);
	rotation(b);
	ft_printf("rr\n");
}
