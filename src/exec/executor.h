/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:30:55 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/08 16:25:15 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../structures/commande/commande.h"
# include <stdbool.h>

int		execute_command(t_commande *command, char ***g_env);

#endif // EXECUTOR_H
