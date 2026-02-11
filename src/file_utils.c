/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   file_utils.c                                          -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/11 15:59:52 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/11 16:30:28 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

#include <fcntl.h>
#include <unistd.h>

#include <error.h>

//Get the size of the file on set path and close it
int	sizing(char *path)
{
	int		fd;
	int		size;
	char	buff[2];

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		free_close_error(path, fd, "CGFS");
	while (read(fd, buff, 1) != 0)
		++size;
	close(fd);
	return (size);
}
