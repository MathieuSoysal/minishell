/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_signal_env_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:29:10 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/29 18:29:43 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void add_signal_env_var(t_adress *env) 
{
    t_variables *signal_var;
    char *value;
    char *name;

    name = strdup("?");
    value = strdup("0");
    signal_var = init_env_variable(name, value, VALUE);
    add_new_env_variable(env, signal_var);
}
