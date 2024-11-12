/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:11 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:50:44 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)pointer;
	while (count)
	{
		*ptr = value;
		ptr++;
		count--;
	}
	return (pointer);
}
