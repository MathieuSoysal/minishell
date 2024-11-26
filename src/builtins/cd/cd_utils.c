/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:11:31 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/25 15:00:43 by kahoumou         ###   ########.fr       */
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

void	env_update_var_cd(char **envp, const char *var, const char *value)
{
	size_t	len;

	if (!*envp)
	{
		len = strlen(var) + strlen(value) + 2;
		*envp = malloc(len);
		if (*envp)
			sprintf(*envp, "%s=%s", var, value);
		envp[1] = NULL;
		return ;
	}
	len = strlen(var);
	if (strncmp(*envp, var, len) == 0 && (*envp)[len] == '=')
	{
		free(*envp);
		len = strlen(var) + strlen(value) + 2;
		*envp = malloc(len);
		if (*envp)
			sprintf(*envp, "%s=%s", var, value);
		return ;
	}
	env_update_var_cd(envp + 1, var, value);
}
void	print_cd_error(char *arg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}


int change_directory(char *path, char *oldpwd)
{
    if (chdir(path) == -1)
    {
        print_cd_error(path);
        free(oldpwd);
        return -1;
    }
    return 0;
}
char *get_oldpwd(char **envp)
{
    char *oldpwd = getcwd(NULL, 0);
    if (!oldpwd)
        oldpwd = ft_strdup(env_get_var(envp, "PWD"));
    return oldpwd;
}
char *get_newpwd(char **envp)
{
    char *newpwd = getcwd(NULL, 0);
    if (!newpwd)
        newpwd = ft_strdup(env_get_var(envp, "PWD"));
    return newpwd;
}
