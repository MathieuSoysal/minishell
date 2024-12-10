/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/10 14:13:22 by kahoumou         ###   ########.fr       */
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
static int	g_interrupt;
void		setup_sigint(void);
// void		signal_sigquit(int sig);
void		signal_command_sigint(int sig);
void		setup_command_signals(void);
void		signal_sigint(int sig);
void		setup_signal_handling(void);
void		handle_interrupt_in_loop(void);
void		restore_signals_for_readline(void);

#endif // SIGINT_H
