/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_lenght.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:11:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:47:44 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

void	ft_putchar_lenght(char c, int *lenght)
{
	write(1, &c, 1);
	(*lenght) += 1;
}
