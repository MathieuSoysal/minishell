/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/08 10:53:51 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../structures/commande/commande.h"
#include "../utils/utils.h"
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	cd(t_commande *cmd, char **envp)
{
	if (!cmd->args[1])
		return (0);
	if (chdir(cmd->args[1]) == -1)
	{
		perror("No such file or directory\n");
		return (1);
	}
	env_update_var(envp, "PWD", getcwd(NULL, 0));
	return (0);
}
