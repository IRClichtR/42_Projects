/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:48:58 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/17 18:05:10 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int	find_smallest(t_pile *pile)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = pile->pile[0][0];
	while (i < pile->size)
	{
		if (pile->pile[0][i] < smallest)
			smallest = pile->pile[0][i];
		i++;
	}
	return (find_idx(pile, smallest));
}
