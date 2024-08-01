/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_existe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:44:58 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:09:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"


int	variable_exist(t_adress *env, char *name)
{
	t_variables	*var;

	var = get_env_var_with_name(env, name);
	if (!var)
		return (0);
	if (ft_same_name(var->name, name))
		return (1);
	return (0);
}