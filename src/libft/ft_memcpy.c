/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:45:31 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:56:25 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	size = (int)size;
	while (size > i)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
