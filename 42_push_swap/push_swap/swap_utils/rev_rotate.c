/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:24:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/09 18:21:30 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	rev_rotate(t_pile *pile, char pile_name)
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
	if (pile_name == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
