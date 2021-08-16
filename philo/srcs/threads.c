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

int check_death(t_philo *philo)
{
	struct timeval  now;
	t_philo		*philo_i;
	int			i;

	i = 0;
	gettimeofday(&now, NULL);
	while (i++ < philo->data->nb)
	{
		philo_i = philo->data->philos[i - 1];
		if (time_diff(&philo_i->last_meal, &now) >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->m_kill);
			philo->data->time_of_death = time_diff(&philo->data->start, &now);
			if (!philo->data->death)
				ft_die(philo_i);
			philo->data->death = 1;
			pthread_mutex_unlock(&philo->data->m_kill);
			return (1);
		}
	}
	return (0);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		ret;

	philo = (t_philo *)arg;
	usleep(MUS_TO_MS * (philo->id % 2));
	while (!philo->data->death)
	{
		if (philo->data->nb_meals > -1 && philo->nb_meals == philo->data->nb_meals)
			return (NULL);
		ret = ft_eat(philo);
		if (ret == 1)
		{
			if (ft_sleep(philo))
				return (NULL);
		}
		else if (ret == -1)
			break ;	
		if (ft_think(philo))
			return (NULL);
	}
	pthread_mutex_unlock(&philo->data->m_kill);
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
	i = 0;
	while (i++ < data->nb)
	{
		philo = data->philos[i - 1];
		pthread_create(&philo->thread, NULL, start_routine, (void *)philo);
		//if (data->death)
		//{
			//printf("death: %d\n", data->death);
			//pthread_mutex_unlock(&data->m_kill);
			//pthread_mutex_unlock(&data->m_msg);
		//	break ;
		//}
	}
	//pthread_mutex_unlock(&data->m_msg);
	//if (data->death)
	//{
	//	pthread_mutex_unlock(&data->m_msg);
		//pthread_mutex_unlock(&data->m_kill);
		//i = 0;
		//while (i++ < data->nb)
		//	pthread_detach(data->philos[i - 1]->thread);
		//return (0);
	//}
	i = 0;
	while (i++ < data->nb)
		if (pthread_join(data->philos[i - 1]->thread, NULL))
			printf("Philo #%d failed to join\n", i);
	return (0);
}
