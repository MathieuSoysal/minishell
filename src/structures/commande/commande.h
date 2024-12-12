/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:36:50 by hsoysal           #+#    #+#             */
/*   Updated: 2024/12/12 17:08:24 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDE_H
# define COMMANDE_H

# include "../../utils/parser/infiles/apply_infiles.h"
# include "../../utils/parser/outfiles/apply_outfiles.h"
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

/**
 * @brief Structure representing a command
 * @param name The name of the command
 * @param args The arguments of the command, its NULL terminated
 * @param infile_name The name of the file to read from
 * @param outfile_name The name of the file to write to
 */
typedef struct s_commande
{
	char		*name;
	char		*path;
	char		**args;
	t_infile	**infiles;
	t_outfile	**outfiles;

	int			g_i;
}				t_commande;

typedef struct s_fd
{
	int			fd_infile;
	int			fd_outfile;
	int			fd[2];
	int			i;
}				t_fd;

t_commande		*commande_create(char **args, char **env);

/**
 * @brief Check if a command has an infile
 * @param commande The command to check
 * @return true if the command has an infile, false otherwise
 */
bool			commande_has_infile(t_commande *commande);

/**
 * @brief Check if a command has an outfile
 * @param commande The command to check
 * @return true if the command has an outfile, false otherwise
 */
bool			commande_has_outfile(t_commande *commande);

/**
 * @brief Free a command
 * @param commande The command to free
 */
void			commande_free(t_commande *commande);

/**
 * @brief Print a command
 * @param commande The command to print
 */
void			print_commande(t_commande *commande);

/**
 * @brief Free a list of commands
 * @param commands The list of commands to free
 */
void			free_commands(t_commande **commands);

/**
 * @brief Set the path of a command,
	if the command is a builtin or path is not found, the path is name
 * @param commande The command
 */
void			commande_set_path(t_commande *commande, char **env);

/**
 * @brief Get the file descriptor of the infile of a command
 * @param commande The command
 * @return The file descriptor of the infile
 */
int				command_get_fd_infile(t_commande *commande);

/**
 * @brief Get the file descriptor of the outfile of a command
 * @param commande The command
 * @return The file descriptor of the outfile
 */
int				command_get_fd_outfile(t_commande *commande);
int				command_count(t_commande **commands);
void			arg_is_void_and_signt_init(int argc, char const argv[]);
void			commands_free(t_commande *command);
void			free_split(char **split);
void			env_update_var_cd(char **envp, const char *var,
					const char *value);
void			print_cd_error(char *arg);
int				change_directory(char *path, char *oldpwd);
void			manage_redirections(t_commande *command, t_commande **commands,
					char ***g_env);
void			handle_input_redirection(t_commande *command,
					t_commande **commands, char ***g_env);
void			handle_output_redirection(t_commande *command,
					t_commande **commands, char ***g_env);
void			print_redirection_error(char *cmd_name);
void			handle_execve_failure(t_commande **commands,
					t_commande *command, char ***g_env);
char			*get_oldpwd(char **envp);
char			*get_newpwd(char **envp);
void			free_cmds(t_commande *commande);
void			error_all_cmd(int status, t_commande *cmd);

#endif // COMMANDE_H
