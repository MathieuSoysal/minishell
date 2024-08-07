/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_change_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:12:41 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 19:27:13 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

char	*take_adresse_of_path(void)
{
	char *res = getcwd(NULL, 0);
	if (res == NULL)
		perror("getcwd() Error\n");
	return (res);
}

char	*take_adress_of_new_path(char **envp)
{
	char * adress_for_new_path;
	char * adress_for_path;
	adress_for_new_path = take_var_for_adress(envp, "PWD");
	adress_for_path = mem_malloc_str(adress_for_new_path);
	return (adress_for_path);
}

char	*take_var_for_adress(char **envp, char *name)
{
	t_variables	*variable;

	variable = take_var_for_next_value(envp, name);
	if (variable)
	{
		return (variable->value);
	}
	return (NULL);
}

t_variables	*take_var_for_next_value(char ** envp, char *name)
{
	t_variables	*variables_env;

	variables_env = variables_env->variables;
	while (variables_env)
	{
		if (ft_strcmp(name, variables_env->name) == 0)
		{
			return (variables_env);
		}
		variables_env = variables_env->next;
	}
	return (NULL);
}

void	changing_var_name(char **envp, char *name, char *value)
{
	t_variables	*variable;

	variable = take_var_for_next_value(envp, name);
	if (variable)
	{
		free(variable->value);
		variable->value = ft_strdup(value);
	}
	else
	{
		variable = malloc(sizeof(t_variables));
		variable->name = ft_strdup(name);
		variable->value = ft_strdup(value);
		variable->next = variable ->variables;
		variable->variables = variable -> variables;
	}
}
