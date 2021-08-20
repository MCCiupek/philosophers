/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:12:25 by mciupek           #+#    #+#             */
/*   Updated: 2021/08/20 12:29:04 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return (print_error(ERR_PROMPT));
	if (parse_args(argv, &data))
		return (1);
	pthread_mutex_init(&data.msg, NULL);
	ft_threads(&data);
	i = 0;
	while (i++ < data.nb)
	{
		pthread_mutex_destroy(&data.philos[i - 1]->fork);
		free(data.philos[i - 1]);
	}
	free(data.philos);
	return (pthread_mutex_destroy(&data.msg));
}
