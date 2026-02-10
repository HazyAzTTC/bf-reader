/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   debug_treating.c                                      -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/02/09 16:52:12 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/10 03:13:38 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "debug_treating.h"

#include <stdlib.h>

#include "error.h"

//Return the length of a string.
int	fn_strlen(char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
		++index;
	return (index - 1);
}

//Return a string to display an entry number
char	*fn_itoa(int number, int *grid, char *file)
{
	int		div;
	int		index;
	char	*str;

	div = 1000000000;
	index = 0;
	str = malloc(9 * 10);
	if (str == NULL)
		free_all_error(file, grid, "EWTD");
	while (div > 1)
	{
		if ((number / div) != 0 || index != 0)
		{
			str[index] = '0' + number;
			index++;
			number = number % div;
		}
		div = div / 10;
	}
	str[index] = '0' + number;
	str[index + 1] = '\0';
	return (str);
}

//Remove all debug characters from the string
//that store the brainfuck code
void	*anti_debug(char *string)
{
	int		index;
	int		pos;
	int		size;
	char	*temp;

	size = fn_strlen(string) + 1;
	temp = malloc(8 * size);
	index = 0;
	pos = 0;
	if (temp == NULL)
		free_char_error(string, "FCDR");
	while (string[index])
	{
		if (string[index] != '#')
		{
			temp[pos] = string[index];
			++pos;
		}
		++index;
	}
	free(string);
	temp[pos] = '\0';
	return (temp);
}
