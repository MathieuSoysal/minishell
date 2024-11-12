/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_malloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:28:52 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/12 19:52:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*mem_malloc_str(char *tab_for_mlc)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(tab_for_mlc) + 1));
	i = 0;
	while (tab_for_mlc[i])
	{
		str[i] = tab_for_mlc[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
