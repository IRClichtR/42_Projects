/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:31:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 17:02:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_pile *a, t_pile *b, int *sorted_tab, int size)
{
	pb_beg(a, b, sorted_tab, size);
	pb_end(a, b, sorted_tab, size);
	pb_mid2(a, b, sorted_tab, size);
	pb_mid1(a, b, sorted_tab, size);
}
