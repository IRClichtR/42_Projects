/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:54:30 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:22:56 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_utils.h"

static int	check_push_case(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int		push_case;
	char	*move_a;
	char	*move_b;

	move_a = select_move(a, idx_a);
	move_b = select_move(b, idx_b);
	if (ft_strncmp(move_a, "rot", 3) == 0
		&& ft_strncmp(move_b, "rot", 3) == 0)
		push_case = 1;
	else if (ft_strncmp(move_a, "rev", 3) == 0
		&& ft_strncmp(move_b, "rev", 3) == 0)
		push_case = 2;
	else if (ft_strncmp(move_a, "rot", 3) == 0
		&& ft_strncmp(move_b, "rev", 3) == 0)
		push_case = 3;
	else if (ft_strncmp(move_a, "rev", 3) == 0
		&& ft_strncmp(move_b, "rot", 3) == 0)
		push_case = 4;
	else
		push_case = 0;
	return (push_case);
}

static void	loop_r_or_rev(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	if (ft_strncmp(select_move(a, idx_a), "rot", 3) == 0)
		loop_ra(a, idx_a);
	else if (ft_strncmp(select_move(a, idx_a), "rev", 3) == 0)
		loop_rra(a, idx_a);
	if (ft_strncmp(select_move(b, idx_b), "rot", 3) == 0)
		loop_rb(b, idx_b);
	else if (ft_strncmp(select_move(b, idx_b), "rev", 3) == 0)
		loop_rrb(b, idx_b);
	push(b, a, 'a');
}

static void	loop_rr_or_rrr(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	if (check_push_case(a, b, idx_a, idx_b) == 1)
		loop_rr(a, b, idx_a, idx_b);
	else if (check_push_case(a, b, idx_a, idx_b) == 2)
		loop_rrr(a, b, idx_a, idx_b);
	else
		return ;
}

void	do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b)
{
	int		save_a;
	int		save_b;

	save_a = value_at_idx(a, idx_a);
	save_b = value_at_idx(b, idx_b);
	if (idx_a == 0 && idx_b == 0 && b->size != 0)
	{
		push(b, a, 'a');
		return ;
	}
	loop_rr_or_rrr(a, b, idx_a, idx_b);
	idx_a = find_idx(a, save_a);
	idx_b = find_idx(b, save_b);
	if (idx_a == 0 && idx_b == 0)
		return ;
	loop_r_or_rev(a, b, idx_a, idx_b);
}
