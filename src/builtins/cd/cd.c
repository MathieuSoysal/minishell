/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:54 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/28 14:50:38 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../minishell.h"
#include "../../signals/sigint/sigint.h"
#include "../../structures/commande/commande.h"
#include "../../structures/env/env.h"
#include "../../utils/parser/parser.h"
#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	cd(t_commande *cmd, char **envp)
{
	char	*oldpwd;
	char	*newpwd;

	if (!cmd->args[1])
		return (0);
	oldpwd = get_oldpwd(envp);
	if (!oldpwd)
		return (2);
	if (change_directory(cmd->args[1], oldpwd) == -1)
		return (127);
	env_update_var_cd(envp, "OLDPWD", oldpwd);
	newpwd = get_newpwd(envp);
	if (!newpwd)
		return (2);
	env_update_var_cd(envp, "PWD", newpwd);
	free(oldpwd);
	free(newpwd);
	return (0);
}
