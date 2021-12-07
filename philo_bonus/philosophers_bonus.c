/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:03:40 by abridger          #+#    #+#             */
/*   Updated: 2021/12/07 20:26:18 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	if (argc != 5 && argc != 6)
		return (put_error_message(&data, 1));
	else if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60
		|| (argc == 6 && ft_atoi(argv[5]) < 0))
		return (put_error_message(&data, 2));
	else
	{
		action(&data, argv);
		ft_all_clear(&data);
	}
	return (0);
}
