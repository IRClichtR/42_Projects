/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_beg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:31:36 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/08 11:52:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

void	pb_beg(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	while (check_if_push_comp(a, sorted_tab, 1, size) == 1)
	{
		if (create_chunks(sorted_tab, size, a->pile[0][0]) == 1)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
}
