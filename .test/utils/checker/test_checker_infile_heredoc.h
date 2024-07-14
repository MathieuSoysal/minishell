
#ifndef TEST_CHECKER_INFILE_HEREDOC_H
# define TEST_CHECKER_INFILE_HEREDOC_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_infile_heredoc(void)
{
	t_syntax_error	error;

	error = check_syntax("<<<<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE_HEREDOC);
	error = check_syntax("<<<<<<<<<<<<<<<<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE_HEREDOC);
	error = check_syntax("cat >> <<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE_HEREDOC);
	error = check_syntax("echo hola <<<<< bonjour\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_INFILE_HEREDOC);
}

void	test_check_syntax_infile_heredoc_all(void)
{
	test_check_syntax_infile_heredoc();
}

#endif // TEST_CHECKER_INFILE_HEREDOC_H
