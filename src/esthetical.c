/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   esthetical.c                                          -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:51:43 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/11 02:52:58 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include <esthetical.h>

#include <unistd.h>

//Doing a little waiting animation for x sec
void	waiter(void)
{
	int	index;

	index = 0;
	while (index < 3)
	{
		sleep(1);
		write(1, ".", 1);
		++index;
	}
	write(1, "\033[0m", 4);
}
