/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ataraxia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:47:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/24 19:01:40 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_thinker(t_philo *think)
{
	pthread_mutex_lock(&think->lock);
	if (get_time() >= think->death_end && check_death(think) == 0)
		write_death(think);
	if (think->data->round_nb > 0 && think->eat_count >= think->data->round_nb)
		write_finish(think);
	pthread_mutex_unlock(&think->lock);
}

void	*death_watch(void *arg)
{
	t_philo	*think;
	int		i;

	think = (t_philo *)arg;
	usleep(2000);
	while (1)
	{
		i = -1;
		while (++i < think->data->think_nb)
			check_thinker(&think->data->think[i]);
		if (check_death(think) == 1)
			break ;
	}
	return ((void *)0);
}

void	*get_ataraxia(void *arg)
{
	t_philo	*think;

	think = (t_philo *)arg;
	pthread_mutex_lock(&think->lock);
	think->death_end = think->data->death_time + get_time();
	pthread_mutex_unlock(&think->lock);
	if (think->think_id % 2 == 0)
		go_sleep(think->data->eat_time * 1 / 2);
	while (1)
	{
		if (check_death(think) == 1 || check_finish(think) == 1)
			break ;
		eat(think);
		display_status(THINK, think);
		if (think->data->think_nb % 2 != 0)
			go_sleep(think->data->eat_time * (think->data->think_nb / 3));
		usleep(1000);
	}
	return ((void *)0);
}
