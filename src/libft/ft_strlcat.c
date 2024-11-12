/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:11:19 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:51:36 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	if (dest == NULL && size == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= size)
		return (size + srclen);
	i = 0;
	while (src[i] && i + destlen < size - 1)
	{
		dest[i + destlen] = src[i];
		i++;
	}
	dest[i + destlen] = '\0';
	return (destlen + srclen);
}
