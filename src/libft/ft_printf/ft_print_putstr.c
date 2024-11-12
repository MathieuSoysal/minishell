/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:28:40 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:22 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_print_putstr(char *str, int *lenght)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		(*lenght) += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar_lenght(str[i], lenght);
		i++;
	}
}
