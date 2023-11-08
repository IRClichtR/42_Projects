/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:05:39 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 14:58:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	loop_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int	size;
	int	biggest;

	if (a->size - idx_a > b->size - idx_b)
	{
		biggest = idx_b;
		size = b->size;
	}
	else
	{
		biggest = idx_a;
		size = a->size;
	}
	while (biggest != size)
	{
		rev_rotate_2(a, b);
		biggest++;
	}
}
