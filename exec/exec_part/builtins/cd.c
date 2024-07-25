/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/24 15:45:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "builtins.h"


int cd(t_cmd *cmd, t_adress  *adress)
{
        if(adress)
        {
                return(0);
        }
        adress = malloc(sizeof(t_adress));

    if (!cmd->arg)
        return 0;

    if (chdir(cmd->arg) == -1)
    {
        perror("No such file or directory\n");
        return 1;
    }
    adress->adress_for_path = take_adresse_of_path(adress);
    adress->adress_for_new_path = take_adress_of_new_path(adress);
    changing_var_name(adress, "PWD", adress->adress_for_path);
    changing_var_name(adress, "OLDPWD", adress->adress_for_new_path);

    free(adress);
    return 0;
}
