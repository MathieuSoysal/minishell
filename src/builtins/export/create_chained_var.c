/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chained_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:25:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/02 15:49:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void	init_all(int index, char **env_variable, t_adress *env,
		t_variables *var)
{
	char	*name;
	char	*value;

	name = my_export_var_name(env_variable[index]);
	value = take_var_value(env_variable[index]);
	var = init_variable(name, value, VALUE);
	add_new_env_variable(env, var);
}

void	create_chained_var(t_adress *env, char **env_variable)
{
	int			index;
	t_variables	*var;

	index = 0;
	var = NULL;
	while (env_variable[index])
	{
		init_all(index, env_variable, env, var);
		index++;
	}
}
