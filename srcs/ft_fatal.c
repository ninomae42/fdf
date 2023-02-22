/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 02:48:39 by tashimiz          #+#    #+#             */
/*   Updated: 2023/02/22 14:53:42 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Prints the error message based on perror and
// prints the user defined error message.
// Then exit with EXIT_FAILURE.
void	ft_fatal(char *err_msg)
{
	perror("fdf");
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *err_msg)
{
	perror("fdf");
	ft_putendl_fd(err_msg, STDERR_FILENO);
}
