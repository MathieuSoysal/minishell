/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:52:16 by kahoumou          #+#    #+#             */
/*   Updated: 2024/11/23 15:47:11 by kahoumou         ###   ########.fr       */
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


void	print_invalid_identifier_error(char *arg)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}


char	*get_env_value(const char *key, char **env)
{
	int		i;
	int		key_len;

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
char	*expand_variables(const char *value, char **env)
{
	static char	result[BUFFER_S];
	char		var_name[BUFFER_S];
	char		*var_value;
	int			i = 0, j = 0, k;

	result[0] = '\0';

	while (value[i] && j < BUFFER_SIZE - 1)
	{
		if (value[i] == '$' && (ft_isalpha(value[i + 1]) || value[i + 1] == '_'))
		{
			i++;
			k = 0;
			while ((ft_isalnum(value[i]) || value[i] == '_') && k < BUFFER_S - 1)
				var_name[k++] = value[i++];
			var_name[k] = '\0';

			var_value = get_env_value(var_name, env);
			if (var_value)
			{
				strncat(result, var_value, BUFFER_SIZE - strlen(result) - 1);
				j = strlen(result);
			}
		}
		else
		{
			result[j++] = value[i++];
			result[j] = '\0';
		}
	}
	return (result);
}