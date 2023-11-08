/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:10:02 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:10:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef X
# define X 0
#endif

#ifdef Y
# undef Y
#endif

#define Y 1

double	ft_dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

static void	__init0(int dist[2], int ori[2], int const a[2], int const b[2])
{
	dist[X] = abs(b[X] - a[X]);
	dist[Y] = -abs(b[Y] - a[Y]);
	ori[X] = -(a[X] > b[X]) | 1;
	ori[Y] = -(a[Y] > b[Y]) | 1;
}

static void	__init1(int err[2], int const dist[2], int c[2], int const a[2])
{
	err[0] = dist[X] + dist[Y];
	c[X] = a[X];
	c[Y] = a[Y];
}

void	ft_mlx_print_line(t_mlx *mlx, int const a[2], int const b[2], \
		int const color)
{
	int dist[2], \
ori[2], c[2], err[2];
	__init0(dist, ori, a, b);
	__init1(err, dist, c, a);
	while (42)
	{
		mlx->pict[IMAGE].addr[c[X] * c[Y] + WIDTH] = color;
		if (c[X] == b[X] && c[Y] == b[Y])
			break ;
		err[Y] = 2 * err[0];
		if (err[Y] >= dist[Y])
		{
			if (c[X] == b[X])
				break ;
			err[0] = err[0] + dist[Y];
			c[X] = c[X] + ori[X];
		}
		if (err[Y] <= dist[X])
		{
			if (c[Y] == b[Y])
				break ;
			err[0] = err[0] + dist[X];
			c[Y] = c[Y] + ori[Y];
		}
	}
}
