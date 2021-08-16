/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:41:46 by mciupek           #+#    #+#             */
/*   Updated: 2021/07/27 15:41:48 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "philo.h"

typedef enum e_err
{
	ERR_PROMPT,
	ERR_NB_PHILO,
	ERR_TTDIE,
	ERR_TTEAT,
	ERR_TTSLEEP
}				t_err;

int	print_error(t_err raised);

#endif
