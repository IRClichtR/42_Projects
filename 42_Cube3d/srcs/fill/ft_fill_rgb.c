/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:54:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/16 07:54:34 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_data(char *str, t_data **data, t_list **list)
{
	free(str);
	ft_clear_all_exit(data, list, SPACEFAIL);
}

void	ft_fill_rgb(t_data **data, t_list **list, int *dst, char *src)
{
	t_list	*tmp;
	char	*to_split;

	tmp = *list;
	to_split = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->line, src, 2) == 0)
		{
			to_split = ft_sub_trim_str(tmp->line, src);
			if (!to_split)
			{
				if (ft_strcmp(src, "F ") == 0)
					ft_clear_all_exit(data, list, FLOORFAIL);
				else if (ft_strcmp(src, "C ") == 0)
					ft_clear_all_exit(data, list, CEILINGFAIL);
			}
			*dst = ft_get_hexa_rgb_values(data, list, &to_split);
			if (*dst == -1)
				ft_free_data(to_split, data, list);
			free(to_split);
		}
		tmp = tmp->next;
	}
}
