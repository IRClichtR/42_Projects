/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_push_comp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:24:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/27 14:48:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	check_if_push_comp(t_pile *src, int *sorted, int chunk, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < src->size)
	{
		if (create_chunks(sorted, size, src->pile[0][i]) == chunk)
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	else
		return (1);
}
