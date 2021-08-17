/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:52:56 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/27 15:52:57 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
long long int	time_diff(struct timeval *start, struct timeval *end);

#endif
