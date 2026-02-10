/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   complex_inputs.c                                      -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:50:35 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/10 03:04:20 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "complex_inputs.h"

#include <unistd.h>
#include <stdlib.h>

#include "debug_treating.h"
#include "error.h"

//Display the current position of the cursor and what value there is there
void	debug_print(int *playground, int cursor, char *file)
{
	int		pos_size;
	char	*pos;
	char	*value;
	char	value_char;

	pos = fn_itoa(cursor, playground, file);
	pos_size = fn_strlen(pos);
	value = fn_itoa(playground[cursor], playground, file);
	value_char = playground[cursor];
	write(1, "Cursor on:", 11);
	write(1, pos, pos_size);
	free(pos);
	write(1, "\nValue is:", 11);
	write(1, value_char, 1);
	write(1, "/", 1);
	write(1, value, 3);
	free(value);
	write(1, "\n", 1);
	return ;
}

//Get the value of a user input and store it at 
//current cursor position in the grid
void	get_char(int *playground, int cursor, char *file)
{
	int		value;
	char	*buffer;

	value = 255;
	buffer = malloc(8 * 1);
	if (buffer == NULL)
		free_all_error("CICR", file, playground);
	write(1, "\nPlease enter an ascii character:\n", 34);
	read(0, buffer, 1);
	value = buffer[0];
	free(buffer);
	playground[cursor] = value;
	return ;
}

//Display the character equivalent to current cursor pos
//in grid stored value
void	put_char(int *playground, int cursor)
{
	char	to_print;

	to_print = playground[cursor];
	write(1, &to_print, 1);
	return ;
}

//Manage the logic of while loops in brainfuck
void	start_while(char *file, int *pos, int *playground, int *cursor)
{
	int	start;

	++pos;
	start = pos;
	while (file[pos] != ']' && playground[cursor] != 0 && file[pos] != 0)
	{
		if (file[pos] == ']' && playground[cursor] != 0)
			pos = start;
		else if (file[pos] == '+' || file[pos] == '-'
			|| file[pos] == '>' || file[pos] == '<')
			input_to_action(file[pos], playground, cursor);
		else
			parsing_complex(file, pos, grid, cursor);
		pos++;
	}
	--pos;
	return ;
}
