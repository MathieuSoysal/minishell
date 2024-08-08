/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:18 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 11:45:19 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_INTERNAL_H
# define EXPORT_INTERNAL_H

# include <stdbool.h>

bool	is_valid_identifier(char *arg);
void	print_invalid_identifier_error(char *arg);
void	apply_export_for_arg(char *arg, char ***g_env);

#endif // EXPORT_INTERNAL_H
