/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 18:33:03 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/28 18:33:04 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	time_diff(struct timeval *start, struct timeval *end)
{
	return (S_TO_MS * (end->tv_sec - start->tv_sec) \
		+ US_TO_MS * (end->tv_usec - start->tv_usec));
}

static long long int	us_time_diff(struct timeval *start, struct timeval *end)
{
	return (S_TO_US * (end->tv_sec - start->tv_sec) \
		+ end->tv_usec - start->tv_usec);
}

int	ft_usleep(int time_in_ms)
{
	struct timeval	start;
	struct timeval	now;
	long long int	time;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	time = time_in_ms * MS_TO_US - 1;
	while (us_time_diff(&start, &now) < time)
	{
		usleep(1);
		gettimeofday(&now, NULL);
	}
	return (0);
}
