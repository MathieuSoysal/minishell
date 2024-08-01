/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_signal_env_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:29:10 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/01 15:13:06 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

void add_signal_env_var(t_adress *env) 
{
    t_variables *signal;
    char *val;
    char *name;

    name = strdup("?");
    val = strdup("0");
    signal = init_variable(name, val, VALUE);
    add_new_env_variable(env, signal);
}
