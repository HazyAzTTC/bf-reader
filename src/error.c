/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   error.c                                               -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 00:02:51 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/10 14:01:08 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#include <unistd.h>
#include <stdlib.h>

//Display error message with error code and abort programm
void	error(char *error_code)
{
	system("clear");
	write(2, "\e[47;31m/!\\ Oops! something went poorly... /!\\\n", 47);
	write(2, "For more details please refer to documentation.\n", 48);
	write(2, "> Error code:", 13);
	write(2, error_code, 4);
	write(2, "\e[0m\nNow aborting execution ", 28);
	write(2, "before anything else happens...\n\n", 32);
	abort();
}

//Free the malloced char and int vars before calling error
void	free_all_error(char *st_free, int *ar_free, char *error_code)
{
	free(st_free);
	free(ar_free);
	error(error_code);
}

//Free the malloced char var before calling error
void	free_char_error(char *to_free, char *error_code)
{
	free(to_free);
	error(error_code);
}

//Free the malloced char var and close the current open FD before calling error
void	free_close_error(char *to_free, int to_close, char *error_code)
{
	free(to_free);
	close(to_close);
	error(error_code);
}

//Free the malloced int var before calling error
void	free_int_error(int *to_free, char *error_code)
{
	free(to_free);
	error(error_code);
}
