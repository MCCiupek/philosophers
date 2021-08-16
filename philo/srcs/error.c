/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:34:45 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/27 15:34:47 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_error_msg(t_err raised)
{
	const char	*errors[] = {"Error: prompt error.\n\
Try: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]",
		"Error: There must be at least 1 philosopher",
		"Error: Time to die must be a positive integer",
		"Error: Time to eat must be a positive integer",
		"Error: Time to sleep must be a positive integer"};

	return ((char *)errors[raised]);
}

int	print_error(t_err raised)
{
	char	*msg;

	msg = get_error_msg(raised);
	ft_putstr_fd(msg, STDERR);
	ft_putstr_fd("\n", STDERR);
	return (1);
}
