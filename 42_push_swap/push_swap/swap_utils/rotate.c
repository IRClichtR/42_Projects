/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:33:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/27 13:36:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	rotate(t_pile *pile, char pile_name)
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
	if (pile_name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}
