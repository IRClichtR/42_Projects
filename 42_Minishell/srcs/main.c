/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:34:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/10 19:34:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error;

int	display_prompt(void)
{
	char	*in;

	while (1)
	{
		in = readline("$>");
		if (in == NULL)
			break ;
		parse_input(in);
		add_history(in);
		rl_on_new_line();
		free(in);
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	(void) av;
	if (ac != 1)
		return (0);
	ft_init_env(ac, av, env);
	ft_init_signal(false);
	if (display_prompt() != SUCCESS)
		ft_putstr_fd("Something wrong happened forcing Minishell to stop!\n",
			2);
	ft_free_all_env(*ft_get_env(0, 0, 0));
	rl_clear_history();
	printf("Minishell stopped normally\n");
	exit(1);
	return (0);
}
