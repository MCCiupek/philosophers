/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:13:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/08/20 12:25:58 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks_odd_total(t_philo *philo)
{
	if (philo->id + 1 != philo->data->nb)
	{
		if (((philo->id + 1) % 2) && !philo->nb_meals)
			usleep(philo->data->time_to_eat * 1000 + 50);
	}
	else
	{
		if (!philo->nb_meals)
			usleep(philo->data->time_to_eat * 500);
	}
	pthread_mutex_lock(&philo->data->philos[philo->next]->fork);
	print_action(philo, RIGHT_FORK, NO_COLOR);
	pthread_mutex_lock(&philo->data->philos[philo->id]->fork);
	print_action(philo, LEFT_FORK, NO_COLOR);
}

void	take_forks_even_total(t_philo *philo)
{
	if (!((philo->id + 1) % 2) && !philo->nb_meals)
		usleep(philo->data->time_to_eat * 999);
	pthread_mutex_lock(&philo->data->philos[philo->next]->fork);
	print_action(philo, RIGHT_FORK, NO_COLOR);
	pthread_mutex_lock(&philo->data->philos[philo->id]->fork);
	print_action(philo, LEFT_FORK, NO_COLOR);
}

int	pick_forks(t_philo *philo)
{
	if (philo->data->nb == 1)
	{
		print_action(philo, LEFT_FORK, NO_COLOR);
		ft_usleep(philo->data->time_to_die * 2);
		return (1);
	}
	if (!(philo->data->nb % 2))
		take_forks_even_total(philo);
	else
		take_forks_odd_total(philo);
	return (0);
}

int	drop_forks(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->data->philos[philo->next]->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->philos[philo->next]->fork);
		pthread_mutex_unlock(&philo->fork);
	}
	return (0);
}
