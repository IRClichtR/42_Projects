/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:02:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/30 13:02:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
	@brief parse the map file. check the extension, open, syntax, dupplicates,
	values and fill data if correct to send to mlx

	@param argc main's argument count
	@param argv main's array of argument's strings
	@param data structure with all infos parsed in map file
	@return nothing
**/

void	ft_parsing(int ac, char **av, t_data **data)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	ft_check_ac(ac, av);
	ft_check_open(av[1], &fd);
	ft_fill_list(fd, &list);
	ft_check_list_syntax(&list);
	ft_check_list_duplicates(&list);
	ft_check_splitted_map(&list);
	ft_check_close(fd, list);
	ft_fill_data(data, &list);
	ft_lst_clear(&list);
	ft_check_textures_extensions(data);
	ft_check_open_textures(data);
	ft_check_player_count(data);
	ft_check_closed_map(data);
}
