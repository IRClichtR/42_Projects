/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:37:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/21 16:37:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

char	*select_move(t_pile *src, int idx)
{
	char	*move;

	if (idx == 0)
		move = "not";
	else if (idx > src->size / 2)
		move = "rev";
	else
		move = "rot";
	return (move);
}
