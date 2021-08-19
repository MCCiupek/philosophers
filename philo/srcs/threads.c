/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:57:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/28 10:57:48 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_checker(void *arg)
{
	struct timeval	now;
	t_data			*data;
	t_philo			*philo;
	int				i;

	data = (t_data *)arg;
	while (!data->death)
	{
		i = 0;
		usleep(1);
		while (i++ < data->nb)
		{
			philo = data->philos[i - 1];
			if (data->nb_meals > -1 && philo->nb_meals == data->nb_meals)
				return (NULL);
			gettimeofday(&now, NULL);
			pthread_mutex_lock(&philo->data->msg);
			if (time_diff(&philo->last_meal, &now) >= data->time_to_die)
			{
				ft_die(philo);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->data->msg);
		}
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//ft_usleep(philo->id % 2);
	while (!philo->data->death)
	{
		if (philo->data->nb_meals > -1 && \
			philo->nb_meals == philo->data->nb_meals)
			break ;
		if (ft_eat(philo))
			ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

t_philo	*init_philo(t_data *data, int i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	data->philos[i - 1] = philo;
	philo->id = i - 1;
	philo->data = data;
	philo->nb_meals = 0;
	philo->last_meal = data->start;
	philo->next = 0;
	if (philo->id < data->nb - 1)
		philo->next = philo->id + 1;
	return (philo);
}

int	ft_threads(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i++ < data->nb)
	{
		philo = init_philo(data, i);
		pthread_mutex_init(&philo->fork, NULL);
	}
	pthread_create(&data->death_checker, NULL, death_checker, (void *)data);
	i = 0;
	while (i < data->nb)
	{
		philo = data->philos[i++];
		pthread_create(&philo->thread, NULL, start_routine, (void *)philo);
	}
	pthread_mutex_unlock(&philo->data->msg);
	pthread_detach(data->death_checker);
	i = 0;
	while (i++ < data->nb)
		pthread_join(data->philos[i - 1]->thread, NULL);
	return (0);
}
