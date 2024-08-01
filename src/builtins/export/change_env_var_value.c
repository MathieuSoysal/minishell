/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_var_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:32:27 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:05:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"


void	change_env_var_value(t_variables *var, char *new_value)
{
	if (var->value)
		free(var->value);
	var->value = new_value;
	var->id = VALUE;
}