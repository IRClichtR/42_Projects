/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:17:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	partition(int **pile, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	i = low;
	j = low;
	pivot_value = pile[0][high];
	while (j < high)
	{
		if (pile[0][j] <= pivot_value)
		{
			ft_swap(&pile[0][i], &pile[0][j]);
			i++;
		}
		j++;
	}
	ft_swap(&pile[0][i], &pile[0][j]);
	return (i);
}

static void	q_sort(int *pile, int beg, int end)
{
	int	pivot_index;

	if (beg < end)
	{
		pivot_index = partition(&pile, beg, end);
		q_sort(pile, beg, pivot_index - 1);
		q_sort(pile, pivot_index + 1, end);
	}
}

int	*sort_pile(t_pile *pile)
{
	int	beg;
	int	end;
	int	i;
	int	*o_pile;

	o_pile = ft_calloc(pile->size, sizeof(int));
	if (!o_pile)
		return (0);
	i = 0;
	while (i < pile->size)
	{
		o_pile[i] = pile->pile[0][i];
		i++;
	}
	beg = 0;
	end = pile->size - 1;
	q_sort(o_pile, beg, end);
	return (o_pile);
}
