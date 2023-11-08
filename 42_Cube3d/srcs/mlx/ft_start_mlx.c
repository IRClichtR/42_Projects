/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:24:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/14 14:24:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef H
# undef H
#endif

#ifdef V
# undef V
#endif

#ifdef X
# undef X
#endif

#ifdef Y
# undef Y
#endif

#define X 0
#define Y 1
#define H 0
#define V 1

void	ft_choose_h_or_v(t_rayon *rayon, double dist[2], double end_pos[2][2])
{
	if (dist[V] < dist[H])
	{
		rayon->dist = dist[V];
		rayon->end_pos[X] = end_pos[V][X];
		rayon->end_pos[Y] = end_pos[V][Y];
		if ((M_PI / 2) < rayon->angle && rayon->angle < (3 * M_PI / 2))
			rayon->type = WALL_EAST;
		else if (rayon->angle < (M_PI / 2) || rayon->angle > (3 * M_PI / 2))
			rayon->type = WALL_WEST;
	}
	else if (dist[H] < dist[V])
	{
		rayon->dist = dist[H];
		rayon->end_pos[X] = end_pos[H][X];
		rayon->end_pos[Y] = end_pos[H][Y];
		if (0 < rayon->angle && rayon->angle < M_PI)
			rayon->type = WALL_NORTH;
		else if (M_PI < rayon->angle && rayon->angle < (2 * M_PI))
			rayon->type = WALL_SOUTH;
	}
}

void	ft_print_min_map(t_mlx *mlx)
{
	int		x;
	int		r;
	float	ra;
	double	dist[2];
	double	end_pos[2][2];

	x = ((r = 0, 0));
	ra = mlx->player[ANGLE] - ((1 * M_PI / 180) * 30);
	while (r < WIDTH)
	{
		if (ra < 0)
			ra += (2 * M_PI);
		else if (ra > 2 * M_PI)
			ra -= (2 * M_PI);
		dist[H] = ft_horizontal_check(mlx, ra, end_pos[H]);
		dist[V] = ft_vertical_check(mlx, ra, end_pos[V]);
		mlx->rayon[r].angle = ra;
		ft_choose_h_or_v(&mlx->rayon[r], dist, end_pos);
		ft_print_3d(mlx, &mlx->rayon[r], ra, &x);
		r += ((ra += (60 * M_PI / 180) / WIDTH, 1));
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->pict[IMAGE].img, 0, 0);
}

void	ft_start_mlx(t_data *data)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	mlx.data = data;
	ft_find_player_pos(data->map, &mlx);
	ft_create_texture(&mlx);
	if (!mlx.mlx_ptr)
		return ;
	ft_print_min_map(&mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, ft_key_hook, &mlx);
	mlx_hook(mlx.win_ptr, ClientMessage, StructureNotifyMask, ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
