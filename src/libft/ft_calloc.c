/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:30:11 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:48:37 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*str;
	size_t	size;
	size_t	count;

	size = elementSize;
	count = elementCount;
	if (count == 0 || size == 0)
		return (malloc(0));
	if ((SIZE_MAX / count) < size)
		return (0);
	str = malloc(count * size);
	if (str == NULL)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}
