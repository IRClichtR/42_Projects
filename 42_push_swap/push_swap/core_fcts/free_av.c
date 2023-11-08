/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:59:43 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 18:05:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **arg_chain)
{
	int	i;

	i = 0;
	while (arg_chain[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(arg_chain[i]);
		arg_chain[i] = NULL;
		i--;
	}
	free(arg_chain);
	arg_chain = NULL;
}
