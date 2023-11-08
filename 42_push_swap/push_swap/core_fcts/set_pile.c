/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:50:42 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 18:03:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_1av_a(t_pile *a, char *av)
{
	char	**args;
	int		i;

	args = ft_split(av, ' ');
	if (args == NULL)
		return ;
	a->size = 1;
	while (args[a->size] != NULL)
		a->size++;
	a->pile[0] = ft_calloc(a->size, sizeof(int));
	if (a->pile[0] == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		a->pile[0][i] = ft_atoi(args[i]);
		i++;
	}
	free_argv(args);
}

static void	set_a(t_pile *a, char **av, int ac)
{
	int	i;

	a->size = ac - 1;
	a->pile[0] = ft_calloc(a->size, sizeof(int));
	if (!a->pile[0])
		return ;
	i = 0;
	while (i < a->size)
	{
		a->pile[0][i] = ft_atoi(av[i]);
		i++;
	}
}

int	set_pile(t_pile *a, t_pile *b, int ac, char **av)
{
	a->pile = ft_calloc(1, sizeof(int *));
	b->pile = ft_calloc(1, sizeof(int *));
	if (!a->pile || !b->pile)
		return (-1);
	if (ac < 3 && av[1] != NULL)
	{
		if (check_av(ac, av) == -1)
			return (free_all(a, b), -1);
		set_1av_a(a, av[1]);
	}
	else
	{
		if (check_av(ac, av) != -1)
			set_a(a, av + 1, ac);
	}
	b->pile[0] = ft_calloc(a->size, sizeof(int));
	if (!b->pile[0])
		return (free_all(a, b), -1);
	return (1);
}
