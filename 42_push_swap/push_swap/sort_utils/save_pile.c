/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:29:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:24:55 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	*save_pile(t_pile *pile)
{
	int	*o_pile;
	int	i;

	i = 0;
	o_pile = ft_calloc(pile->size, sizeof(int));
	if (!o_pile)
		return (0);
	while (i < pile->size)
	{
		o_pile[i] = pile->pile[0][i];
		i++;
	}
	return (o_pile);
}
