/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:11:01 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 17:11:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (*tab)
	{
		i++;
		tab++;
	}
	return (i);
}
