/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:18:17 by abridger          #+#    #+#             */
/*   Updated: 2021/11/16 17:21:03 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_minus(char temp)
{
	int	minus;

	if (temp == 45)
		minus = (-1);
	else
		minus = 1;
	return (minus);
}

static long long	ft_convert(char temp, long long result)
{
	if (temp >= 48 && temp <= 57)
		result = result * 10 + (temp - 48);
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			minus;

	res = 0;
	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		minus = ft_minus(str[i]);
		i++;
	}
	if (str[i] >= 48 && str[i] <= 57)
	{
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = ft_convert(str[i], res);
			i++;
		}
	}
	return (((int)res * minus));
}
