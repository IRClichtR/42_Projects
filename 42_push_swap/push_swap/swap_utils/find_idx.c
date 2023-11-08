/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:17 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

int	find_idx(t_pile *src, int elt)
{
	int	idx;

	idx = 0;
	while (idx < src->size)
	{
		if (elt == src->pile[0][idx])
			return (idx);
		idx++;
	}
	return (0);
}
