/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_mid1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:17:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:17:04 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

void	pb_mid1(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	while (check_if_push_comp(a, sorted_tab, 2, size) == 1)
	{
		if (create_chunks(sorted_tab, size, a->pile[0][0]) == 2)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
}
