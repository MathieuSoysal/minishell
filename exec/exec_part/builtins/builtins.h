/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:22:32 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/11 19:07:22 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUILTINS_H
        #define BUILTINS_H
			#include "libft/libft.h"
            #include<stdlib.h>
            #include<string.h>
            #include<errno.h>
            #include<unistd.h>
            #include<stdbool.h>
            #include<sys/wait.h>
            #include<sys/types.h>
            #include<fcntl.h>

typedef struct s_env
{
    int verbose;
    int error_parsing;
    int error_processing;
    char **env_vars;
} t_env;

typedef struct s_variables
{
    char *first_variable;
    char *name;
    struct s_variables *previous;
    struct s_variables *next;
    char *value;
} t_variables;

typedef struct s_adress
{
    char *adress_for_path;
    char *adress_for_new_path;
    char *adress_absolu;
    t_variables *variable;
} t_adress;

typedef struct s_cmd
{
    int id;
    char *content;
    char *flags;
    char *bin;
    char **args;
    char *arg;
    int fd_in;
    int fd_out;
    int pid;
    char *path;
} t_cmd;




          
int cd(t_cmd *cmd, t_env  *env);
char *mem_malloc_str(char *tab_for_mlc);
int builtins_init(t_env *env, t_cmd *cmd);
char *take_adresse_of_path(t_adress *adress);
char *take_adress_of_new_path(t_adress *adress);
void changing_var_name(t_adress *adresse, char *name, char *value);
t_variables *take_var_for_value(t_adress *adress, char *name);
char *take_var_for_adress(t_adress *adress, char *name);	
			
	
	
	
#endif

