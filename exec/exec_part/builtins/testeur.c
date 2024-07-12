/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:03:59 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/11 18:54:28 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

// Fonction pour initialiser les variables d'environnement
void init_env(t_env *env)
{
    env->verbose = 0;
    env->error_parsing = 0;
    env->error_processing = 0;
    env->env_vars = NULL;
}

// Fonction pour initialiser les commandes
void init_cmd(t_cmd *cmd, char *arg)
{
    cmd->id = 0;
    cmd->content = NULL;
    cmd->flags = NULL;
    cmd->bin = NULL;
    cmd->args = NULL;
    cmd->arg = arg;
    cmd->fd_in = 0;
    cmd->fd_out = 0;
    cmd->pid = 0;
    cmd->path = NULL;
}

// Fonction principale pour tester la commande cd
int main()
{
    t_env env;
    t_cmd cmd;
    t_adress adress;

    // Initialisation des variables d'environnement
    init_env(&env);
    
    // Initialisation des variables d'adresse
    adress.variable = NULL;
    
    // Initialisation de la variable PWD
    changing_var_name(&adress, "PWD", getcwd(NULL, 0));
    changing_var_name(&adress, "OLDPWD", getcwd(NULL, 0));

    // Test 1: Changer de répertoire vers "/tmp"
    init_cmd(&cmd, "/tmp");
    if (cd(&cmd, &env) == 0)
    {
        printf("CD to /tmp successful\n");
        printf("PWD: %s\n", take_var_for_adress(&adress, "PWD"));
        printf("OLDPWD: %s\n", take_var_for_adress(&adress, "OLDPWD"));
    }
    else
    {
        printf("CD to /tmp failed\n");
    }

    // Test 2: Changer de répertoire vers un répertoire inexistant
    init_cmd(&cmd, "/nonexistent");
    if (cd(&cmd, &env) != 0)
    {
        printf("CD to /nonexistent failed as expected\n");
    }

    // Test 3: Revenir au répertoire précédent
    init_cmd(&cmd, take_var_for_adress(&adress, "OLDPWD"));
    if (cd(&cmd, &env) == 0)
    {
        printf("CD to previous directory successful\n");
        printf("PWD: %s\n", take_var_for_adress(&adress, "PWD"));
        printf("OLDPWD: %s\n", take_var_for_adress(&adress, "OLDPWD"));
    }
    else
    {
        printf("CD to previous directory failed\n");
    }

    return 0;
}

