/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cardinal_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:06:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 16:06:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_cardinal_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}