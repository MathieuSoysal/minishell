/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:18 by hsoysal           #+#    #+#             */
/*   Updated: 2024/11/23 14:19:08 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_INTERNAL_H
# define EXPORT_INTERNAL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include "../../libft/libft.h"
#define BUFFER_S 4096

bool	is_valid_identifier(char *arg);
void	apply_export_for_arg(char *arg, char ***g_env);
void	print_sorted_env(char **env);
void	print_invalid_identifier_error(char *arg);
bool	env_contains_var(char **env, char *key);
void	env_update_var(char **env, char *key, char *value);
void	env_add_var(char ***env, char *key, char *value);
char	*get_env_value(const char *key, char **env);
char	*expand_variables(const char *value, char **env);
char	**copy_env(char **env);
void	sort_env(char **env);
void	free_env(char **env);

#endif // EXPORT_INTERNAL_H
