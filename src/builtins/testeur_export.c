/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:44:24 by kahoumou          #+#    #+#             */
/*   Updated: 2024/07/30 17:07:12 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"



void test_export_built_in() 
{
    t_adress env = {0};
    t_cmd cmd = {0};

    // Initialisation de l'environnement et de la commande
    env.variable = NULL;
    cmd.fd_out = 1; // sortie standard

    // Test 1: Ajouter une nouvelle variable
    cmd.arg = "NEW_VAR=test_value";
    export(&cmd, &env);
    printf("Test 1: Ajouter NEW_VAR=test_value\n");
    print_all_adress_fd(&env, 1);

    // Test 2: Ajouter une variable sans valeur
    cmd.arg = "EMPTY_VAR=";
    export(&cmd, &env);
    printf("Test 2: Ajouter EMPTY_VAR=\n");
    print_all_adress_fd(&env, 1);

    // Test 3: Modifier une variable existante
    cmd.arg = "NEW_VAR=new_value";
    export(&cmd, &env);
    printf("Test 3: Modifier NEW_VAR=new_value\n");
    print_all_adress_fd(&env, 1);

    // Test 4: Afficher toutes les variables
    cmd.arg = NULL;
    printf("Test 4: Afficher toutes les variables\n");
    export(&cmd, &env);

    // Nettoyage de la mémoire allouée
    t_variables *var = env.variable;
    t_variables *next_var;
    while (var) {
        next_var = var->next;
        free(var->name);
        free(var->value);
        free(var);
        var = next_var;
    }
}
