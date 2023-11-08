/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var_to_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:23:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 10:23:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_add_var_to_env(t_env **env, char *to_add)
{
	t_env	*new;

	if (!(*env))
	{
		(*env) = malloc(sizeof(t_env));
		if (!(*env))
			return (NULL);
		(*env)->next = NULL;
		(*env)->var = ft_strdup(to_add);
		(*env)->key = ft_get_key_section((*env)->var, (*env)->key);
		(*env)->value = ft_get_value_section((*env)->var, (*env)->value);
		return ((*env)->var);
	}
	else
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (NULL);
	}
	ft_get_last_env(*env)->next = new;
	new->var = ft_strdup(to_add);
	new->key = ft_get_key_section(new->var, new->key);
	new->value = ft_get_value_section(new->var, new->value);
	new->next = NULL;
	return (new->var);
}
