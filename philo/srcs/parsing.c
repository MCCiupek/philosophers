/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:05:20 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/27 17:05:23 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(t_data *data)
{
	if (data->nb < 1)
		return (print_error(ERR_NB_PHILO));
	if (data->time_to_die < 1)
		return (print_error(ERR_TTDIE));
	if (data->time_to_eat < 1)
		return (print_error(ERR_TTEAT));
	if (data->time_to_sleep < 1)
		return (print_error(ERR_TTSLEEP));
	return (0);
}

int	parse_args(char **tab, t_data *data)
{
	data->nb = ft_atoi(tab[1]);
	data->nb_meals = -1;
	data->time_to_die = ft_atoi(tab[2]);
	data->time_to_eat = ft_atoi(tab[3]);
	data->time_to_sleep = ft_atoi(tab[4]);
	if (tab[5])
		data->nb_meals = ft_atoi(tab[5]);
	data->death = 0;
	data->philos = (t_philo **)malloc(sizeof(t_philo *) * data->nb);
	gettimeofday(&data->start, NULL);
	return (check_args(data));
}
