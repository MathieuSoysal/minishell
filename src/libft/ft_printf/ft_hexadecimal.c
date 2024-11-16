/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:32:13 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:05 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal(unsigned int nb, int *lenght, char hex)
{
	int		i;
	char	*str;
	char	take[25];

	i = 0;
	if (nb == 0)
	{
		ft_putchar_lenght('0', lenght);
		return ;
	}
	if (hex == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	while (nb != 0)
	{
		take[i] = str[nb % 16];
		i++;
		nb = nb / 16;
	}
	while (i--)
		ft_putchar_lenght(take[i], lenght);
}
