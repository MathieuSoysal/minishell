/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:12:00 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:48:33 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tab;
	int				i;

	tab = (unsigned char *)s;
	i = 0;
	while (n)
	{
		tab[i] = '\0';
		i++;
		n--;
	}
}
