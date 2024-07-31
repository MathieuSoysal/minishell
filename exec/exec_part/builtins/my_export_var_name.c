/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export_var_name.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:04:27 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/29 16:09:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*my_export_var_name(char *variable)
{
	int	index;
	int	start;
	int	end;

	index = 0;
	start = 0;
	end = 0;
	if (!variable)
	{
		return (NULL);
	}
	while (variable[index])
	{
		if (is_blank(variable[index]))
			return (NULL);
		else if (variable[index] == '=')
		{
			end = index - 1;
			return (malloc_substrcpy(variable, start, end));
		}
		index++;
	}
	end = index;
	return (malloc_substrcpy(variable, start, end));
}
