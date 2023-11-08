/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:30:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:54:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_pile *a, t_pile *b)
{
	if (a->pile[0])
	{
		free(a->pile[0]);
		a->pile[0] = NULL;
	}
	if (b->pile[0])
	{
		free(b->pile[0]);
		b->pile[0] = NULL;
	}
	if (a->pile)
	{
		free(a->pile);
		a->pile = NULL;
	}
	if (b->pile)
	{
		free(b->pile);
		b->pile = NULL;
	}
	free(a);
	a = NULL;
	free(b);
	b = NULL;
}
