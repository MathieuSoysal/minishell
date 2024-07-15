
#ifndef TEST_CHECKER_H
# define TEST_CHECKER_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_pipe_no_error(void)
{
	t_syntax_error	error;

	error = check_syntax("ls -l");
	TEST_CHECK(error == NO_ERROR);
	error = check_syntax("ls echo \"|||| hola ceta\" | cat | cat");
	TEST_CHECK(error == NO_ERROR);
	error = check_syntax("ls | cat | cat");
	TEST_CHECK(error == NO_ERROR);
	error = check_syntax("echo hola || cat");
	TEST_CHECK(error == NO_ERROR);
}

void	test_check_syntax_pipe(void)
{
	t_syntax_error	error;

	error = check_syntax("ls | | cat\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("ls | cat | | cat\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("echo hola ||| cat\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("echo hola | | cat\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("| | |\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("echo | |\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("|echo|\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("|");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("              | hola");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax(">>|><\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
	error = check_syntax("echo salut\n| echo Salut\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_PIPE);
}

void	test_check_syntax_pipe_all(void)
{
	test_check_syntax_pipe_no_error();
	test_check_syntax_pipe();
}

#endif // TEST_CHECKER_H
