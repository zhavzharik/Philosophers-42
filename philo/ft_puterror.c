/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:12:17 by abridger          #+#    #+#             */
/*   Updated: 2021/11/04 01:32:35 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	put_err_str(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
}

void	put_error_message(int check)
{
	write(STDERR_FILENO, "Error: ", 7);
	if (check == 1)
		put_err_str("The wrong number of arguments!");
	else if (check == 2)
		put_err_str("The wrong argument(s)!");
	else if (check == 3)
		put_err_str("Failed to create thread!");
	else if (check == 4)
		put_err_str("Failed to join thread!");
	else if (check == 5)
			put_err_str("Failed to init mutex!");
	//break;
}