/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:25:45 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:07:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	same_name(char *first, char *second)
{
	if (same_str(first, second, ft_strlen(second)))
	{
		return (1);
	}
	return (0);
}