/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:03:59 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/25 14:19:11 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"

// // Fonction pour initialiser les variables d'environnement
// void init_env(t_adress *env)
// {
//     env->verbose = 0;
//     env->error_parsing = 0;
//     env->error_processing = 0;
//     env->env_vars = NULL;
// }

// // Fonction pour initialiser les commandes
// void init_cmd(t_cmd *cmd, char *arg)
// {
//     cmd->id = 0;
//     cmd->content = NULL;
//     cmd->flags = NULL;
//     cmd->bin = NULL;
//     cmd->args = NULL;
//     cmd->arg = arg;
//     cmd->fd_in = 0;
//     cmd->fd_out = 0;
//     cmd->pid = 0;
//     cmd->path = NULL;
// }

// // void_init_variables(t_variables)
// // {
// //     char				*first_variable = NULL;
// // 	char				*name =   NULL;
// // 	struct s_variables	*previous = NULL;
// // 	struct s_variables	*next =   NULL;
// // 	char				*value =  NULL;
// // 	int					index  = NULL;
// // 	int					id = NULL;
// // }

// int open_fd(char *tab, int nb)
// {
//     int fd ;
//     if(nb ==  0)
//     fd = open(tab, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//      if(nb ==  1)
//         fd = open(tab , O_RDONLY);
//     if (fd == -1) 
//     {
//         perror("Failed to open test output file");
//         return 1;
//     }
//     return(fd);
// }
// // Fonction pour simuler la création d'un contexte t_cmd
// t_cmd *create_cmd(char *arg, char **flags, int fd_out) 
// {
//     t_cmd *cmd = malloc(sizeof(t_cmd));
//     if (!cmd) return NULL;

//     cmd->arg = arg ? strdup(arg) : NULL;  // Copier les chaînes si nécessaire
//     cmd->flags = flags;
//     cmd->fd_out = fd_out;
    
//     return cmd;
// }

// // Fonction pour nettoyer le contexte t_cmd
// void free_cmd(t_cmd *cmd) {
//     if (cmd) {
//         if (cmd->arg) free(cmd->arg);
//         free(cmd);
//     }
// }

// // Fonction principale pour tester la commande cd
// int main()
// {
    
//     t_cmd cmd;
//     t_adress adress;
//     t_variables var1 = {"USER", "john", NULL, NULL, NULL};
//     t_variables var2 = {"PATH", "/usr/bin:/bin", &var1, NULL, NULL};
//     t_adress env = {NULL, NULL, NULL, 0, 0, 0, NULL, &var1};

//     // var1.next = &var2;
//      // Affichage du contenu de test_output.txt pour vérification
//     char buffer[1024];
    
//     int test_fd =  open_fd("test_output.txt", 0);
//     int fd2 =  open_fd("test_output.txt", 1);
//     int fd3 =  open_fd("test_output.txt", 1);
//     if(fd3 == 0)
//     {
//         printf("pass\n");
//     }
    
//     // Test 1: Argument simple sans flags
//      char *args1 = "Hello World";
//     char *flags1[] = {NULL};
    
//     t_cmd *cmd1 = create_cmd(args1, flags1, test_fd);
//     echo(cmd1);
     
//     free_cmd(cmd1);
     
//      // Test 2: Argument avec flag `-n`
//     char *args2 = "Hello again";
//     char *flags2[] = {"-n", NULL};
//     t_cmd *cmd2 = create_cmd(args2, flags2, test_fd);
//     echo(cmd2);
//     free_cmd(cmd2);
   
    
//      // Test 3: Aucun argument, aucun flag
//     t_cmd *cmd3 = create_cmd(NULL, NULL, test_fd);
//     echo(cmd3);
//     free_cmd(cmd3);

//     close(test_fd);


//     // Initialisation des variables d'environnement
//     init_env(&adress);
    
//     // Initialisation des variables d'adresse
//     adress.variable = NULL;
    
//     // Initialisation de la variable PWD
//     changing_var_name(&adress, "PWD", getcwd(NULL, 0));
//     changing_var_name(&adress, "OLDPWD", getcwd(NULL, 0));

//     // Test 1: Changer de répertoire vers "/tmp"
//     init_cmd(&cmd, "/tmp");
//     if (cd(&cmd, &adress) == 0)
//     {
//         printf("CD to /tmp successful\n");
//         printf("PWD: %s\n", take_var_for_adress(&adress, "PWD"));
//         printf("OLDPWD: %s\n", take_var_for_adress(&adress, "OLDPWD"));
//     }
//     else
//     {
//         printf("CD to /tmp failed\n");
//     }

// {

// }

//     // Test 2: Changer de répertoire vers un répertoire inexistant
//     init_cmd(&cmd, "/nonexistent");
//     if (cd(&cmd, &adress) != 0)
//     {
//         printf("CD to /nonexistent failed as expected\n");
//     }

//     // Test 3: Revenir au répertoire précédent
//     init_cmd(&cmd, take_var_for_adress(&adress, "OLDPWD"));
//     if (cd(&cmd, &adress) == 0)
//     {
//         printf("CD to previous directory successful\n");
//         printf("PWD: %s\n", take_var_for_adress(&adress, "PWD"));
//         printf("OLDPWD: %s\n", take_var_for_adress(&adress, "OLDPWD"));
//     }
//     else
//     {
//         printf("CD to previous directory failed\n");
//     }

    
//     ssize_t bytes_read;
//     while ((bytes_read = read(fd2, buffer, sizeof(buffer) - 1)) > 0) {
//         buffer[bytes_read] = '\0';
//         printf("%s", buffer);
//     }
    
//     close(fd2);
//      print_all_adress_fd(&env, 1);
//     test_export_built_in();
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "builtins.h"

// Fonction pour initialiser les variables d'environnement
void init_env(t_adress *env)
{
    env->verbose = 0;
    env->error_parsing = 0;
    env->error_processing = 0;
    env->env_vars = NULL;
    env->first_line = NULL;
    env->first_token = NULL;
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

int open_fd(char *tab, int nb)
{
    int fd;
    if (nb == 0)
        fd = open(tab, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (nb == 1)
        fd = open(tab, O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open test output file");
        return -1;
    }
    return fd;
}

// Fonction pour simuler la création d'un contexte t_cmd
t_cmd *create_cmd(char *arg, char **flags, int fd_out)
{
    t_cmd *cmd = malloc(sizeof(t_cmd));
    if (!cmd) return NULL;

    cmd->arg = arg ? strdup(arg) : NULL; // Copier les chaînes si nécessaire
    cmd->flags = flags;
    cmd->fd_out = fd_out;

    return cmd;
}

// Fonction pour nettoyer le contexte t_cmd
void free_cmd(t_cmd *cmd)
{
    if (cmd)
    {
        if (cmd->arg) free(cmd->arg);
        free(cmd);
    }
}

// Fonction principale pour tester la commande cd
int main()
{
    t_cmd cmd;
    t_adress adress;
    t_variables var1 = {"USER", "john", NULL, NULL, NULL};
    // t_variables var2 = {"PATH", "/usr/bin:/bin", &var1, NULL, NULL}; // Commented out since it is unused
    t_adress env = {NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, &var1};

    // Initialisation des variables d'environnement
    init_env(&adress);

    // var1.next = &var2;
    // Affichage du contenu de test_output.txt pour vérification
    char buffer[1024];

    int test_fd = open_fd("test_output.txt", 0);
    int fd2 = open_fd("test_output.txt", 1);
    int fd3 = open_fd("test_output.txt", 1);
    if (fd3 == 0)
    {
        printf("pass\n");
    }

    // Test 1: Argument simple sans flags
    char *args1 = "Hello World";
    char *flags1[] = {NULL};

    t_cmd *cmd1 = create_cmd(args1, flags1, test_fd);
    echo(cmd1);

    free_cmd(cmd1);

    // Test 2: Argument avec flag `-n`
    char *args2 = "Hello again";
    char *flags2[] = {"-n", NULL};
    t_cmd *cmd2 = create_cmd(args2, flags2, test_fd);
    echo(cmd2);
    free_cmd(cmd2);

    // Test 3: Aucun argument, aucun flag
    t_cmd *cmd3 = create_cmd(NULL, NULL, test_fd);
    echo(cmd3);
    free_cmd(cmd3);

    close(test_fd);

    // Initialisation des variables d'environnement
    init_env(&adress);

    // Initialisation des variables d'adresse
    adress.variable = NULL;

    // Initialisation de la variable PWD
    changing_var_name(&adress, "PWD", getcwd(NULL, 0));
    changing_var_name(&adress, "OLDPWD", getcwd(NULL, 0));

    // Test 1: Changer de répertoire vers "/tmp"
    init_cmd(&cmd, "/tmp");
    if (cd(&cmd, &adress) == 0)
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
    if (cd(&cmd, &adress) != 0)
    {
        printf("CD to /nonexistent failed as expected\n");
    }

    // Test 3: Revenir au répertoire précédent
    init_cmd(&cmd, take_var_for_adress(&adress, "OLDPWD"));
    if (cd(&cmd, &adress) == 0)
    {
        printf("CD to previous directory successful\n");
        printf("PWD: %s\n", take_var_for_adress(&adress, "PWD"));
        printf("OLDPWD: %s\n", take_var_for_adress(&adress, "OLDPWD"));
    }
    else
    {
        printf("CD to previous directory failed\n");
    }

    ssize_t bytes_read;
    while ((bytes_read = read(fd2, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(fd2);
    print_all_adress_fd(&env, 1);
    test_export_built_in();
    return 0;
}
    

