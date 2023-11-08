/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:50:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:52:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_left(t_pile *a)
{
	int		*o_tab;

	o_tab = save_pile(a);
	if (check_if_sorted(a->pile[0], a->size) == 1)
		return ;
	sort_3(a, o_tab);
	free(o_tab);
}
