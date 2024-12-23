/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/23 13:59:05 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGINT_H
# define SIGINT_H
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>

static int	g_sigint;
void		setup_sigint(void);
// void		signal_sigquit(int sig);
void		signal_command_sigint(int sig);
void		setup_command_signals(void);
void		signal_sigint(int sig);
void		setup_signal_handling(void);
void		restore_signals_for_readline(void);
void		handle_process_signal(int status);
void		restore_signals_for_cmd(int signal);

#endif // SIGINT_H
