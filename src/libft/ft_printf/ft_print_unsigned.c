/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:10:53 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int nb, int *lenght)
{
	int	c;

	if (nb < 0)
	{
		c = '0' + nb;
		ft_putchar_lenght(c, lenght);
	}
	else if (nb > 9)
		ft_print_putnbr((nb / 10), lenght);
	ft_print_putnbr(nb % 10, lenght);
}
