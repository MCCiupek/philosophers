/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:08:02 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/28 18:08:03 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_action(t_philo *philo, char *msg, char *color)
{
	struct timeval  now;

	check_death(philo);
	if (philo->data->death)
		return (1);
	gettimeofday(&now, NULL);
	//pthread_mutex_lock(&philo->data->m_msg);
	printf("%s[%010lli]\t%sPhilo %d %s\n%s", \
		GREY, \
		time_diff(&philo->data->start, &now), \
		color, \
		philo->id + 1, \
		msg, \
		NO_COLOR);
	//pthread_mutex_unlock(&philo->data->m_msg);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	t_data 	*data;
	int	next;

	data = philo->data;
	next = 0;
	if (philo->id < data->nb - 1)
		next = philo->id + 1;
	check_death(philo);
	if (philo->data->death)
		return (-1);
	if (next == philo->id || pthread_mutex_lock(&philo->fork))
		return (0);
	if (print_action(philo, LEFT_FORK, NO_COLOR))
		return (-1);
	if (pthread_mutex_lock(&data->philos[next]->fork))
	{
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}
	if (print_action(philo, RIGHT_FORK, NO_COLOR))
		return (-1);
	gettimeofday(&philo->last_meal, NULL);
	if (print_action(philo, EAT, GREEN))
		return (0);
	usleep(philo->data->time_to_eat * MUS_TO_MS);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&data->philos[next]->fork);
	philo->nb_meals++;
	return (1);
}

int	ft_sleep(t_philo *philo)
{
	if (print_action(philo, SLEEP, CYAN))
		return (1);
	usleep(philo->data->time_to_sleep * MUS_TO_MS);
	return (0);
}

int	ft_think(t_philo *philo)
{
	return (print_action(philo, THINK, YELLOW));
}

int ft_die(t_philo *philo)
{
	struct timeval  now;

	gettimeofday(&now, NULL);
	//pthread_mutex_lock(&philo->data->m_msg);
	printf("%s[%010lli]\t%sPhilo %d %s at %lli\n%s", \
		GREY, \
		time_diff(&philo->data->start, &now), \
		RED, \
		philo->id + 1, \
		DIE, \
		philo->data->time_of_death, \
		NO_COLOR);
	/*printf(GREY);
	printf("[%010lli]\t", \
		time_diff(&philo->data->start, &now));
	printf("%s", RED);
	printf("Philo %d %s at %lli\n", \
		philo->id + 1, \
		DIE, \
		philo->data->time_of_death);
	printf(NO_COLOR);*/
	//pthread_mutex_unlock(&philo->data->m_msg);
	return (0);
}
