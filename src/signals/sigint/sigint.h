/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/09 23:16:55 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGINT_H
# define SIGINT_H

# define _POSIX_C_SOURCE 200809L

char	***get_envp(char **envp);
void	free_env(char **env);
void	setup_sigint(void);

#endif // SIGINT_H
