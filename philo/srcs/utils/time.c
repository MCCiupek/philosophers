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

long long int time_diff(struct timeval *start, struct timeval *end)
{
	return (1 / S_TO_MS * (end->tv_sec - start->tv_sec) \
		+ 1 / MUS_TO_MS * (end->tv_usec - start->tv_usec));
}
