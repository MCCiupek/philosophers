/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:13:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/27 14:13:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# include "error.h"
# include "utils.h"

/**
** Actions
**/

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"
# define LEFT_FORK "has taken a fork"
# define RIGHT_FORK "has taken a fork"
# define DROP_LEFT_FORK "has dropped his left fork"
# define DROP_RIGHT_FORK "has dropped his right fork"

/**
** Colors
**/

# define BLACK "\033[1;30m"
# define GREY "\033[1;90m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define NO_COLOR "\033[0;37m"

/**
** File-Descriptors
**/

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/**
** Constant
**/

# define MS_TO_S 1e-6
# define US_TO_MS 1e-3
# define MS_TO_US 1e3
# define US_TO_MS 1e-3
# define S_TO_US 1e6
# define S_TO_MS 1e3

/**
** Data
**/

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				id;
	int				next;
	struct timeval	last_meal;
	int				nb_meals;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				death;
	long long		time_of_death;
	struct timeval	start;
	t_philo			**philos;
	pthread_t		death_checker;
//	pthread_mutex_t	kill;
	pthread_mutex_t	msg;
}					t_data;

/**
** Functions
**/

int	parse_args(char **tab, t_data *data);
int	ft_threads(t_data *data);
int	pick_forks(t_philo *philo);
int	drop_forks(t_philo *philo);
int	print_action(t_philo *philo, char *msg, char *color);
int	ft_eat(t_philo *philo);
int	ft_sleep(t_philo *philo);
int	ft_think(t_philo *philo);
int	ft_die(t_philo *philo);
int	check_death(t_philo *philo);
int	ft_usleep(int time);

#endif
