/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:14:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/30 17:14:56 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



int	same_str(char *first, char *second, int size)
{
	int	i;

	if (size < 0)
		size = ft_strlen(first);
	i = 0;
	while (first[i] && second[i] && i < size)
	{
		if (first[i] != second[i])
			return (0);
		++i;
	}
	if (i == size)
		return (1);
	return (0);
}
