/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 03:13:19 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 03:15:05 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell$ "

/**
 * @brief Get the exit status of a process
 * @param status The status of the process,if is -1,
	the function will returnpast status
 */
int	get_exit_status(int status);

#endif // MINISHELL_H
