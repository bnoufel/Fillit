/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchedal- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:51:25 by jchedal-          #+#    #+#             */
/*   Updated: 2017/11/08 17:01:33 by jchedal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int abs_n;

	abs_n = n;
	if (n < 0)
	{
		abs_n = -n;
		ft_putchar('-');
	}
	if (abs_n > 9)
	{
		ft_putnbr(abs_n / 10);
		ft_putchar(abs_n % 10 + '0');
	}
	else
		ft_putchar(abs_n + '0');
}
