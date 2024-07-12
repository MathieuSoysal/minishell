/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:44:43 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/11 14:57:04 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int builtins_init(t_env  *env, t_cmd *cmd)
{
    int status;
    status = -1;
        if  (for_cd(cmd))
            status = cd(cmd, env);
    
}