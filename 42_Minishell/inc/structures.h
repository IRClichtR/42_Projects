/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:27:24 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/04 17:35:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdbool.h>
# include "enum.h"

typedef struct s_token
{
	char			*word;
	t_type			type;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char			*var;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	t_token			*args;
	t_token			*rdir;
	int				fd[2];
	int				pid;
	struct s_cmd	*next;
}				t_cmd;

#endif // !STRUCTURES_H
