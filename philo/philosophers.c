/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:03:40 by abridger          #+#    #+#             */
/*   Updated: 2021/11/06 23:47:56 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
		put_error_message(&data, 1);
	else
	{
		action(&data, argv);
		//put_input(&data, argv);
		//start_threads(&data);
		//join_threads(&data);
		ft_all_clear(&data);
	}
	return (0);
}