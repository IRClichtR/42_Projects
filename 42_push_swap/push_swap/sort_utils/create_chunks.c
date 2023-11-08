/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:59:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:16:25 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

int	create_chunks(int *sorted_tab, int size, int elt)
{
	int	i;

	i = -1;
	while (++i < size / 4)
		if (elt == sorted_tab[i] && elt != sorted_tab[0])
			return (1);
	i -= 1;
	while (++i < size / 2)
		if (elt == sorted_tab[i])
			return (2);
	i -= 1;
	while (++i < size * 3 / 4 && elt != sorted_tab[size / 2])
		if (elt == sorted_tab[i])
			return (3);
	i -= 1;
	while (++i < size && elt != sorted_tab[size - 1])
		if (elt == sorted_tab[i])
			return (4);
	return (0);
}
