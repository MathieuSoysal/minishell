/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chained_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:25:05 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:06:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void create_chained_var(t_adress *env, char **env_variable) 
{
    int index = 0;
    char *name;
    char *value;
    t_variables *var;

    while (env_variable[index]) {
        name = my_export_var_name(env_variable[index]);
        value = take_var_value(env_variable[index]);
        var = init_variable(name, value, VALUE);
        add_new_env_variable(env, var);
        index++;
    }
}


