/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:56:20 by abridger          #+#    #+#             */
/*   Updated: 2021/11/08 17:52:06 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_timestamp(void)
{
	struct timeval	tv;
	long long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_stamp);
}
