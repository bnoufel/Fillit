/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:51:33 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 17:01:36 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	abs_n = n;
	if (n < 0)
	{
		abs_n = -n;
		ft_putchar_fd('-', fd);
	}
	if (abs_n > 9)
	{
		ft_putnbr_fd(abs_n / 10, fd);
		ft_putchar_fd(abs_n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(abs_n + '0', fd);
}
