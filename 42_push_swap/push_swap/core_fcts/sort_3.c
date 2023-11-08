/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:08:37 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:58:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pile *a, int *o_tab)
{
	if (a->size == 2)
		swap_pile(a, 'a');
	else
	{
		if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2] && o_tab[2] < o_tab[0])
			rotate(a, 'a');
		else if (o_tab[0] > o_tab[1] && o_tab[1] < o_tab[2]
			&& o_tab[0] < o_tab[2])
			swap_pile(a, 'a');
		else if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2]
			&& o_tab[2] < o_tab[0])
			rev_rotate(a, 'a');
		else if (o_tab[0] > o_tab[1] && o_tab[1] > o_tab[2])
		{
			swap_pile(a, 'a');
			rev_rotate(a, 'a');
		}
		else if (o_tab[0] < o_tab[1] && o_tab[1] > o_tab[2])
		{
			swap_pile(a, 'a');
			rotate(a, 'a');
		}
	}
}
