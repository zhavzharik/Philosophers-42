/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 23:16:05 by abridger          #+#    #+#             */
/*   Updated: 2021/11/06 23:45:41 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	action(t_data *data, char **argv)
{
	put_input(data, argv);
	data->start_time = get_timestamp();
	printf("Time_stamp %lli\n", data->start_time);
	start_threads(data);
	join_threads(data);
	ft_mutex_init(data);
	return (0);
}