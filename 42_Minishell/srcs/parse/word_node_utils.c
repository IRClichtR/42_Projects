/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:04:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 12:13:55 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*goto_last_node(t_token *ptr)
{
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	addback_cmdline_node(t_token **cmd_line, t_token *new)
{
	t_token	*last_ad;

	if (!*cmd_line)
	{
		*cmd_line = new;
		return ;
	}
	last_ad = goto_last_node(*cmd_line);
	last_ad->next = new;
}

int	append_cmd_node(t_token *cmd_line, char *line)
{
	t_token	*new_node;

	new_node = cmdline_new_node(line);
	if (!new_node)
		return (FAILURE);
	addback_cmdline_node(&cmd_line, new_node);
	return (SUCCESS);
}

t_token	*cmdline_new_node(char *input)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (0);
	new->word = input;
	new->next = NULL;
	return (new);
}

t_token	*add_all_words_nodes( char **tab)
{
	t_token	*cmd_line;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			cmd_line = cmdline_new_node(tab[0]);
			if (!cmd_line)
				return (NULL);
		}
		else
			if (append_cmd_node(cmd_line, tab[i]) == FAILURE)
				return (NULL);
		if (!cmd_line)
			return (NULL);
		i++;
	}
	return (cmd_line);
}
