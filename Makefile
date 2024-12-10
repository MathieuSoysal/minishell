NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -lreadline
#ftrapv
# Add color variables
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
NC := \033[0m

SRC = ./src/exec/without_pipe/exec_builtins.c \
		./src/exec/without_pipe/exec_external.c \
		./src/exec/without_pipe/free_execute_external_command.c \
		./src/exec/without_pipe/exec_external_utils.c\
		./src/exec/without_pipe/single_exec.c \
		./src/exec/all_executors/executor_internal.c \
		./src/exec/all_executors/executor_builtins.c \
		./src/exec/with_pipes/child_process.c \
		./src/exec/with_pipes/dup.c \
		./src/exec/with_pipes/fork_pid.c \
		./src/exec/with_pipes/exec_cmd.c \
		./src/exec/with_pipes/process_command.c \
		./src/exec/check_files.c \
		./src/exec/perm_denied_No_such.c \
		./src/utils/parser/infiles/infile.c \
		./src/utils/parser/infiles/apply_infiles.c \
		./src/utils/parser/outfiles/apply_outfiles.c \
		./src/utils/parser/string_formater/apply_dollars.c \
		./src/utils/parser/string_formater/internal_formater.c \
		./src/utils/parser/string_formater/split_by_space.c \
		./src/utils/parser/string_formater/apply_strings.c \
		./src/utils/parser/string_formater/internal_parser.c \
		./src/utils/parser/parser.c \
		./src/utils/checker/checker.c \
		./src/utils/checker/internal_checker.c \
		./src/utils/here_doc/here_doc.c \
		./src/utils/mini_libft/utils_2.c \
		./src/utils/mini_libft/utils.c \
		./src/utils/mini_libft/get_next_line.c \
		./src/builtins/cd/cd.c \
		./src/builtins/cd/cd_utils.c\
		./src/builtins/echo/echo.c \
		./src/builtins/echo/echo_internal.c \
		./src/builtins/env/env.c \
		./src/builtins/exit/exit.c \
		./src/builtins/export/export.c \
		./src/builtins/export/is_valid.c \
		./src/builtins/export/export_internal.c \
		./src/builtins/export/print_invalid_identifier_error.c\
		./src/builtins/export/env_add_var_for_export.c\
		./src/builtins/pwd/pwd.c \
		./src/builtins/unset/unset.c \
		./src/libft/ft_atoi.c \
		./src/libft/ft_bzero.c \
		./src/libft/ft_calloc.c \
		./src/libft/ft_isalnum.c \
		./src/libft/ft_isalpha.c \
		./src/libft/ft_isascii.c \
		./src/libft/ft_isdigit.c \
		./src/libft/ft_isprint.c \
		./src/libft/ft_itoa.c \
		./src/libft/ft_lstadd_back.c \
		./src/libft/ft_lstadd_front.c \
		./src/libft/ft_lstclear.c \
		./src/libft/ft_lstdelone.c \
		./src/libft/ft_lstiter.c \
		./src/libft/ft_lstlast.c \
		./src/libft/ft_lstnew.c \
		./src/libft/ft_lstsize.c \
		./src/libft/ft_memchr.c \
		./src/libft/ft_memcmp.c \
		./src/libft/ft_memcpy.c \
		./src/libft/ft_memmove.c \
		./src/libft/ft_memset.c \
		./src/libft/ft_printf/ft_hexadecimal.c \
		./src/libft/ft_printf/ft_pourcentage.c \
		./src/libft/ft_printf/ft_print_pointeur.c \
		./src/libft/ft_printf/ft_print_putnbr.c \
		./src/libft/ft_printf/ft_print_putstr.c \
		./src/libft/ft_printf/ft_print_unsigned.c \
		./src/libft/ft_printf/ft_printf.c \
		./src/libft/ft_printf/ft_printf_fd.c \
		./src/libft/ft_printf/ft_putchar_lenght.c \
		./src/libft/ft_printf/count_putchar_fd.c \
		./src/libft/ft_putchar_fd.c \
		./src/libft/ft_putendl_fd.c \
		./src/libft/ft_putnbr_fd.c \
		./src/libft/ft_putstr_fd.c \
		./src/libft/ft_same_name.c \
		./src/libft/ft_split.c \
		./src/libft/ft_strchr.c \
		./src/libft/ft_strcmp.c \
		./src/libft/ft_striteri.c \
		./src/libft/ft_strlcat.c \
		./src/libft/ft_strlcpy.c \
		./src/libft/ft_strlen.c \
		./src/libft/ft_strmapi.c \
		./src/libft/ft_strncmp.c \
		./src/libft/ft_strnstr.c \
		./src/libft/ft_strrchr.c \
		./src/libft/ft_strtrim.c \
		./src/libft/ft_substr.c \
		./src/libft/ft_tolower.c \
		./src/libft/ft_touper.c \
		./src/libft/get_next_line/get_next_line_utils.c \
		./src/libft/get_next_line/get_next_line.c \
		./src/libft/malloc_substrcpy.c \
		./src/libft/mem_malloc_str.c \
		./src/libft/op_ternary.c \
		./src/libft/ft_intcmp.c \
		./src/libft/free_array.c \
		./src/libft/ft_strdup.c \
		./src/libft/ft_strjoin.c \
		./src/prompteur/git_prompt.c \
		./src/prompteur/prompteur.c \
		./src/signals/exit_status.c \
		./src/signals/sigint/sigint.c \
		./src/signals/sigint/restore_signals_for_readline.c\
		./src/structures/commande/command_path.c \
		./src/structures/commande/commande_free.c \
		./src/structures/commande/commande.c \
		./src/structures/commandes/commandes.c \
		./src/structures/commandes/commandes_utils.c \
		./src/structures/double_linked_list/double_linked_list_head.c \
		./src/structures/double_linked_list/double_linked_list_optional.c \
		./src/structures/double_linked_list/double_linked_list_tail.c \
		./src/structures/double_linked_list/double_linked_list_essentials.c \
		./src/structures/env/env_utils.c \
		./src/structures/env/env_essentials.c \
		./src/structures/node.c \
		./src/command_count.c \
		./src/main.c \
		./src/is_not_empty.c\
		./src/arg_is_void_and_signt_init.c

# Update OBJ to place .o files into $(BUILD_DIR)
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))
BUILD_DIR = build
OUTFILE = $(BUILD_DIR)/$(NAME)

all: $(NAME)
	@echo "$(YELLOW)Building $(NAME)...$(NC)"

# Compilation rule to create .o files in $(BUILD_DIR)
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<... Please wait.$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Update $(NAME) target to use object files from $(BUILD_DIR)
$(NAME): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJ) $(LDFLAGS)
	@echo "$(GREEN)Built and deployed at $(OUTFILE)$(NC)"

# Update clean target to remove object files from $(BUILD_DIR)
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(BUILD_DIR)/**/*.o

fclean: clean
	@echo "$(RED)Cleaning build directory...$(NC)"
	@rm -rf $(BUILD_DIR)

re: fclean all

# valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=valgrind_ignore  ./build/minishellv    
