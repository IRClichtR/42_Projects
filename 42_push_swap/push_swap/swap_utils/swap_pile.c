/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:55 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:47:00 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

void	swap_pile(t_pile *pile, char pile_name)
{
	if (pile->size < 2)
		return ;
	ft_swap(&pile->pile[0][0], &pile->pile[0][1]);
	if (pile_name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
