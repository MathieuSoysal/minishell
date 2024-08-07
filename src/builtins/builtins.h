/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/08/07 19:32:48 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# define VALUE 1
# define NONE_VALUE 2
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#include "../structures/commande/commande.h"


typedef struct s_line
{
	int					index;
	char				*content;
	struct s_line		*next;
	struct s_line		*prev;

}						t_line;

typedef struct s_token
{
	void				*class;
	int					id;
	int					index;
	struct s_token		*next;
	struct s_token		*prev;

}						t_token;

typedef struct s_variables
{
	char				*first_variable;
	char				*name;
	struct s_variables	*previous;
	struct s_variables	*next;
	char				*value;
	int					index;
	int					id;
	t_variables			variables;
	
}						t_variables;

typedef struct s_adress
{
	char				*adress_for_path;
	char				*adress_for_new_path;
	char				*adress_absolu;
	int					verbose;
	int					error_parsing;
	int					error_processing;
	char				**env_vars;
	t_line				*first_line;
	t_token				*first_toke;

}						t_adress;

typedef struct s_cmd
{
	int					id;
	char				*content;
	char				**flags;
	char				*bin;
	char				**args;
	char				*arg;
	int					fd_in;
	int					fd_out;
	int					pid;
	char				*path;
}						t_cmd;

int						cd(t_commande *cmd, char **envp);
char					*mem_malloc_str(char *tab_for_mlc);
int						builtins_init(t_adress *env, t_cmd *cmd);
char					*take_adresse_of_path(void);
char					*take_adress_of_new_path(t_adress *adress);
void					changing_var_name(t_adress *adresse, char *name,
							char *value);
char					*take_var_for_adress(t_adress *adress, char *name);
t_variables				*take_var_for_next_value(t_adress *adress, char *name);
int						export(t_cmd *cmd, t_adress *env);
t_variables				*my_first_variable(t_adress *env);
void					print_env_var_fd(t_variables *var, int fd);
void					print_all_adress_fd(t_adress *env, int fd);
char					*my_export_var_name(char *variable);
void					change_or_create_var(t_adress *env, char *name,
							char *value, int id);
int						ft_same_name(char *name1, char *name2);
t_variables				*get_env_var_with_name(t_adress *env, char *name);
void					change_env_var_value(t_variables *var, char *value);
int						variable_exist(t_adress *env, char *name);
t_variables				*init_variable(char *name, char *value, int id);
void					add_new_env_variable(t_adress *env, t_variables *new);
t_variables				*get_last_env_var(t_adress *env);
char					*take_var_value(char *variable);
void					change_env_value_with_name(t_adress *env, char *name, char *value);
void 					create_chained_var(t_adress *env, char **env_variable);
t_variables				*init_variable(char *name, char *value, int id);
void					add_signal_env_var(t_adress *env);
int						is_var_id(char *value);
int						variable_exist(t_adress *env, char *name);
int						same_name(char *first, char *second);
int						same_str(char *first, char *second, int size);
void					free_array(char **array); 
void					test_export_built_in(); 
int						is_blank(char c);
int						echo(t_commande *cmd);
int						pwd(t_cmd *cmd);
void					test_export_built_in();

#endif
