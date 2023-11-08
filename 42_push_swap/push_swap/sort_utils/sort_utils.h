/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:31:14 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:28:17 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define  SORT_UTILS_H

# include "../core_fcts/push_swap.h"

int		check_if_push_comp(t_pile *a, int *sorted_tab, int chunk, int size);
int		check_if_sorted(int *tab, int size);
int		create_chunks(int *sorted_tab, int size, int elt);
void	do_best_push(t_pile *a, t_pile *b, int idx_a, int idx_b);
void	pb_beg(t_pile *a, t_pile *b, int *sorted_tab, int size);
void	pb_end(t_pile *a, t_pile *b, int *sorted_tab, int size);
void	pb_mid1(t_pile *a, t_pile *b, int *sorted_tab, int size);
void	pb_mid2(t_pile *a, t_pile *b, int *sorted_tab, int size);
char	*program_move(t_pile *a, t_pile *b, int idx_a, int idx_b);
int		*save_pile(t_pile *pile);
int		save_size(t_pile *src);
int		select_idxb(t_pile *a, t_pile *b);
char	*select_move(t_pile *src, int idx);
int		*sort_pile(t_pile *pile);
#endif
