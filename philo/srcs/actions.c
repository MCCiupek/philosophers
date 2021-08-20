/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:08:02 by mciupek           #+#    #+#             */
/*   Updated: 2021/08/20 12:39:04 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(t_philo *philo, char *msg, char *color)
{
	struct timeval	now;

	if (philo->data->death)
		return (1);
	pthread_mutex_lock(&philo->data->msg);
	gettimeofday(&now, NULL);
	printf("%s[%010lli]\t%s%d %s\n%s", \
		GREY, \
		time_diff(&philo->data->start, &now), \
		color, \
		philo->id + 1, \
		msg, \
		NO_COLOR);
	pthread_mutex_unlock(&philo->data->msg);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (pick_forks(philo))
		return (0);
	gettimeofday(&philo->last_meal, NULL);
	if (print_action(philo, EAT, GREEN))
		return (-1);
	ft_usleep(philo->data->time_to_eat);
	drop_forks(philo);
	philo->nb_meals++;
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (print_action(philo, SLEEP, CYAN))
		return (1);
	ft_usleep(philo->data->time_to_sleep);
	return (philo->data->death);
}

int	ft_think(t_philo *philo)
{
	return (print_action(philo, THINK, YELLOW));
}

int	*ft_die(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	philo->data->time_of_death = time_diff(&philo->data->start, &now);
	printf("%s[%010lli]\t%s%d %s\n%s", \
		GREY, \
		time_diff(&philo->data->start, &now), \
		RED, \
		philo->id + 1, \
		DIE, \
		NO_COLOR);
	philo->data->death = 1;
	return (NULL);
}
