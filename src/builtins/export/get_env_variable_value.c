/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_variable_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:39:09 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 16:54:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

int	is_value_null(char *value)
{
	if (value[0] == '\0')
		return (1);
	return (0);
}

char	*take_var_value(char *variable)
{
	int		i;
	int		start;
	int		end;
	char	*value;

	i = 0;
	if (!variable)
		return (NULL);
	while (variable[i])
	{
		if (variable[i] == '=' && !(is_blank(variable[i + 1])))
		{
			start = i + 1;
			end = ft_strlen(variable);
			value = malloc_substrcpy(variable, start, end);
			if (is_value_null(value))
			{
				free(value);
				return (NULL);
			}
			return (value);
		}
		i++;
	}
	return (NULL);
}
