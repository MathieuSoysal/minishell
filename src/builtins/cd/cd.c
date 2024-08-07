/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 19:19:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"
#include "../../structures/commande/commande.h"

int	cd(t_commande *cmd, char **envp)
{

	char * adress_for_path;
	char * adress_for_new_path;
	if (!cmd->args[1])
		return (0);
	if (chdir(cmd->args[1]) == -1)
	{
		perror("No such file or directory\n");
		return (1);
	}
	adress_for_path = take_adresse_of_path();
	adress_for_new_path = take_adress_of_new_path(envp);
	changing_var_name(envp, "PWD", adress_for_path);
	changing_var_name(envp, "OLDPWD", adress_for_new_path);
	free(envp);
	return (0);
}
