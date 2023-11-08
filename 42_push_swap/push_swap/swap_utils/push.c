/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:48:59 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:49:24 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap_utils.h"

static void	put_zero(t_pile *dest)
{
	int	last;
	int	i;

	last = find_last_idx(dest);
	i = last + 1;
	while (i > 0)
	{
		ft_swap(&dest->pile[0][last], &dest->pile[0][i]);
		if (last == 0)
			break ;
		i--;
		last--;
	}
}

static void	rotation(t_pile *pile)
{
	int	i;
	int	last;

	if (pile->size < 2)
		return ;
	i = 0;
	last = find_last_idx(pile);
	while (i < last)
	{
		ft_swap(&pile->pile[0][i], &pile->pile[0][i + 1]);
		i++;
	}
}

void	push(t_pile *src, t_pile *dest, char dest_name)
{
	if (src->size == 0)
		return ;
	put_zero(dest);
	ft_swap(&src->pile[0][0], &dest->pile[0][0]);
	if (src->size > 1)
		rotation(src);
	src->size -= 1;
	dest->size += 1;
	if (dest_name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
