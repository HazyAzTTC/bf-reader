/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   error.c                                               -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 00:02:51 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/09 02:43:42 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "error.h"

//display error message with error code and abort programm
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

//free the malloced var (surely the grid) before calling error
void	free_int_error(int *to_free, char *error_code)
{
	free(to_free);
	error(error_code);
}
