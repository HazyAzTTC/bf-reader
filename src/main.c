/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   main.c                                                -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:50:01 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/11 15:42:03 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "core.h"
#include "error.h"
#include "esthetical.h"

//Verify with how many args the program is launched
//and send feedback when necessary
int	arg_nb_verif(int input)
{
	if (input == 1 || input == 2)
		return (input);
	else
	{
		if (input < 1)
			error("NEAL");
		else
			error("TMAL");
	}
	return (3);
}

//Checking if user input == default or debug
int	check(char *input)
{
	int		index;
	int		word;
	char	*list_opt[2];

	word = 0;
	list_opt[0] = "default";
	list_opt[1] = "debug";
	while (word < 2)
	{
		index = 0;
		while (input[index] == list_opt[word][index] && index < 8)
		{
			if (input[index] == '\0' && list_opt[word][index] == '\0')
				return (word);
			index++;
		}
		word++;
	}
	return (2);
}

//Prompt the user for the path of the brainfuck code file
char	*get_path(void)
{
	int		end_path;
	char	*path;

	system("clear");
	path = malloc(300);
	if (path == NULL)
		error("PVCI");
	write(1, "Please enter the path to your BF code:\n", 39);
	end_path = read(0, path, 300);
	end_path--;
	system("clear");
	path[end_path] = '\0';
	return (path);
}

//Writing info for user and launching with correct mode
void	launching(int debug)
{
	char	*path;

	if (debug == 0)
		write(1, "\033[32mLaunching Program In Default Mode", 38);
	else if (debug == 1)
		write(1, "\033[36mLaunching Program In Debug Mode", 37);
	else
	{
		write(2, "\e[47;31m/!\\Error While Reading", 30);
		write(2, " Execution Mode/!\\\e[0m", 22);
		write(1, "\n\033[32m==>Launching Program In Default Mode", 42);
	}
	waiter();
	write(1, "\n", 1);
	path = get_path();
	interpret_file(path, debug);
	return ;
}

//First program function assuring correct parsing and execution
int	main(int argc, char **argv)
{
	int	mode;

	write(1, "\e[2K\r", 5);
	if (arg_nb_verif(argc) == 2)
	{
		mode = check(argv[1]);
		launching(mode);
	}
	else if (arg_nb_verif(argc) != 3)
		launching(0);
	return (0);
}
