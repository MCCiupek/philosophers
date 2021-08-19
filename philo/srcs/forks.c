/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:13:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/08/18 17:13:48 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	left_handed_pick(t_philo *philo)
{
	//if (pthread_mutex_lock(&philo->fork))
	//	return (0);
	pthread_mutex_lock(&philo->fork);
	print_action(philo, LEFT_FORK, NO_COLOR);
	//if (print_action(philo, LEFT_FORK, NO_COLOR))
	//	return (-1);
	pthread_mutex_lock(&philo->data->philos[philo->next]->fork);
	/*if (pthread_mutex_lock(&philo->data->philos[philo->next]->fork))
	{
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}*/
	print_action(philo, RIGHT_FORK, NO_COLOR);
	/*if (print_action(philo, RIGHT_FORK, NO_COLOR))
		return (-1);*/
	return (0);
}
/*
static int	right_handed_pick(t_philo *philo)
{
	//pthread_mutex_lock(&philo->data->philos[philo->next]->fork);
	if (pthread_mutex_lock(&philo->data->philos[philo->next]->fork))
		return (0);
	print_action(philo, RIGHT_FORK, NO_COLOR);
	//if (print_action(philo, RIGHT_FORK, NO_COLOR))
	//	return (-1);
	//pthread_mutex_lock(&philo->fork);
	if (pthread_mutex_lock(&philo->fork) || print_action(philo, LEFT_FORK, NO_COLOR))
	{
		pthread_mutex_unlock(&philo->data->philos[philo->next]->fork);
		return (0);
	}
	//print_action(philo, LEFT_FORK, NO_COLOR);
	//if (print_action(philo, LEFT_FORK, NO_COLOR))
	//	return (-1);
	return (0);
}*/

int	pick_forks(t_philo *philo)
{
	if (philo->data->nb == 1)
	{
		print_action(philo, LEFT_FORK, NO_COLOR);
		ft_usleep(philo->data->time_to_die * 2);
		return (1);
	}
	//if (!(philo->id % 2))
	left_handed_pick(philo);
	//else
	//	right_handed_pick(philo);
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
