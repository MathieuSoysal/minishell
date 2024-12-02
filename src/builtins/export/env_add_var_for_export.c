/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add_var_for_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:31:46 by kahoumou          #+#    #+#             */
/*   Updated: 2024/12/02 11:38:17 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "export_internal.h"

char	*construct_env_var(const char *key, const char *value)
{
	char	*new_var;
	char	*temp;

	if (!key || !value)
		return (NULL);
	new_var = ft_strjoin(key, "=");
	if (!new_var)
		return (NULL);
	temp = ft_strjoin(new_var, value);
	free(new_var);
	if (!temp)
		return (NULL);
	return (temp);
}


void	add_var_to_env(char ***env, char *new_var)
{
	int		env_len;
	int		i;
	char	**new_env;

	if (!new_var || !env || !*env)
		return ;
	env_len = 0;
	while ((*env)[env_len])
		env_len++;
	new_env = malloc(sizeof(char *) * (env_len + 2));
	if (!new_env)
	{
		free(new_var);
		return ;
	}
	for (i = 0; i < env_len; i++)
		new_env[i] = (*env)[i];
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
}






void	add_var_to_env_for_export(char ***env, char *new_var)
{
	int		env_len;
	int		i;
	char	**new_env;

	if (!new_var || !env || !*env)
		return ;
	env_len = 0;
	while ((*env)[env_len])
		env_len++;
	new_env = malloc(sizeof(char *) * (env_len + 2));
	if (!new_env)
	{
		free(new_var);
		return ;
	}
	for (i = 0; i < env_len; i++)
		new_env[i] = (*env)[i];
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
}

void	env_add_var_for_export(char ***env, const char *key, const char *value)
{
	char	*new_var;

	new_var = construct_env_var(key, value);
	if (!new_var)
		return ;
	add_var_to_env(env, new_var);
}
