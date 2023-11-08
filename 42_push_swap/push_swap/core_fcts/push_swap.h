/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:35:35 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 18:11:53 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "type_define.h"
# include "../ft_printf/ft_printf.h"
# include "../swap_utils/swap_utils.h"
# include "../sort_utils/sort_utils.h"

int		check_av(int ac, char **av);
int		check_num(char *arg);
void	free_all(t_pile *a, t_pile *b);
void	free_argv(char **arg_chain);
void	push_back(t_pile *a, t_pile *b);
void	push_swap(t_pile *pile_a, t_pile *pile_b);
void	push_to_b(t_pile *a, t_pile *b, int *sorted_tab, int size);
int		set_pile(t_pile *a, t_pile *b, int ac, char **av);
void	sort_3(t_pile *a, int *o_tab);
void	sort_5(t_pile *a, t_pile *b);
void	sort_a_left(t_pile *a);
#endif
