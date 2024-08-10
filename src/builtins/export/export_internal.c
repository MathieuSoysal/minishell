/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:32:54 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 19:05:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../structures/env/env.h"
#include "export_internal.h"

bool	is_valid_identifier(char *arg)
{
	int	i;

	i = 0;
	if (!arg[i] || !(ft_isalpha(arg[i]) || arg[i] == '_'))
		return (false);
	while (arg[++i])
		if (!(ft_isalnum(arg[i]) || arg[i] == '_' || arg[i] == '='))
			return (false);
	return (true);
}

void	print_invalid_identifier_error(char *arg)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	apply_export_for_arg(char *arg, char ***g_env)
{
	char	*key;
	char	*value;

	if (ft_strchr(arg, '=') != NULL)
	{
		key = ft_substr(arg, 0, ft_strchr(arg, '=') - arg);
		value = ft_strchr(arg, '=') + 1;
		if (env_contains_var(*g_env, key))
			env_update_var(*g_env, key, value);
		else
			env_add_var(g_env, key, value);
	}
}
