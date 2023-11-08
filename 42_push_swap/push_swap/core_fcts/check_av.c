/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 17:54:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dif(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_args(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		if (check_num(av[0]) == -1)
			return (-1);
		return (1);
	}
	i = 0;
	while (av[i])
	{
		if (check_num(av[i]) == -1)
			return (-1);
		i++;
	}
	if (check_dif(av) == -1)
		return (-1);
	return (1);
}

int	check_av(int ac, char **av)
{
	char	**arg;
	int		i;
	int		check;

	if (ac < 2)
		return (-1);
	arg = ft_calloc(ac, sizeof(char *));
	if (arg == NULL)
		return (-1);
	i = 0;
	while (i < ac - 1)
	{
		arg[i] = ft_strdup(av[i + 1]);
		i++;
	}
	check = check_args(ac, arg);
	while (i != -1)
	{
		free(arg[i]);
		arg[i] = NULL;
		i--;
	}
	free(arg);
	return (check);
}
