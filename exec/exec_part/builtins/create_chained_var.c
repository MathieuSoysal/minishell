/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chained_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:25:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/30 14:20:07 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void create_chained_var(t_adress *env, char **env_variable) 
{
    int index = 0;
    char *name;
    char *value;
    t_variables *var;

    while (env_variable[index]) {
        name = get_export_variable_name(env_variable[index]);
        value = get_env_variable_value(env_variable[index]);
        var = init_variable(name, value, VALUE);
        add_new_env_variable(env, var);
        index++;
    }
}


