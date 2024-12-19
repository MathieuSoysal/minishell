/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:52:16 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/28 15:45:19 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "export_internal.h"

bool	is_valid_identifier(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (false);
	if (!(ft_isalpha(arg[0]) || arg[0] == '_'))
		return (false);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!(ft_isalnum(arg[i]) || arg[i] == '_'))
			return (false);
		i++;
	}
	return (true);
}

char	*get_env_value(const char *key, char **env)
{
	int	i;
	int	key_len;

	key_len = strlen(key);
	i = 0;
	while (env[i])
	{
		if (!strncmp(env[i], key, key_len) && env[i][key_len] == '=')
			return (env[i] + key_len + 1);
		i++;
	}
	return ("");
}

char	*get_variable_value(const char *value, int *index, char **env)
{
	char	var_name[BUFFER_S];
	char	*var_value;
	int		k;

	k = 0;
	(*index)++;
	while ((ft_isalnum(value[*index]) || value[*index] == '_') && k < BUFFER_S
		- 1)
		var_name[k++] = value[(*index)++];
	var_name[k] = '\0';
	var_value = get_env_value(var_name, env);
	return (var_value);
}

static int	handle_variable(const char *value, int *index, char *result,
		char **env)
{
	char	*var_value;

	var_value = get_variable_value(value, index, env);
	if (var_value)
	{
		strncat(result, var_value, BUFFER_S - strlen(result) - 1);
		return (strlen(result));
	}
	return (-1);
}

char	*expand_variables(const char *value, char **env)
{
	static char	result[BUFFER_S];
	int			indices[2];

	indices[0] = 0;
	indices[1] = 0;
	result[0] = '\0';
	while (value[indices[0]] && indices[1] < BUFFER_S - 1)
	{
		if (value[indices[0]] == '$' && (ft_isalpha(value[indices[0] + 1])
				|| value[indices[0] + 1] == '_'))
			indices[1] = handle_variable(value, &indices[0], result, env);
		else
		{
			result[indices[1]++] = value[indices[0]++];
			result[indices[1]] = '\0';
		}
	}
	return (result);
}
