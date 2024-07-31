/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_or_create_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:38:37 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/23 17:13:46 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void change_or_create_var(t_adress *env,  char *name, char *value, int id)
{
    t_variables *var;

    if(variable_exist(env, name))
    {
        change_env_value_with_name(env,  name, value);
        free(name);
    }
    else
    {
        var =  init_variable(name, value, id);
        add_new_env_variable(env, var);
    }
}
