/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   complex_inputs.c                                      -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:50:35 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/11 17:00:04 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "complex_inputs.h"

#include <unistd.h>
#include <stdlib.h>

#include "core.h"
#include "debug_treating.h"
#include "error.h"
#include "esthetical.h"

//Display the current position of the cursor and what value there is there
void	debug_print(int *playground, int *cursor, char *file)
{
	int		pos_size;
	char	buffer[10];
	char	*pos;
	char	*value;
	char	value_char;

	pos = fn_itoa(*cursor, playground, file);
	pos_size = fn_strlen(pos) + 1;
	if (playground[*cursor] != 0)
	{
		value = fn_itoa(playground[*cursor], playground, file);
		value_char = playground[*cursor];
	}
	write(1, "\e7\nCursor on: ", 15);
	write(1, pos, pos_size);
	if (pos[0] != '0')
		free(pos);
	if (playground[*cursor] != 0)
	{
		display_value(value, value_char);
		free(value);
	}
	write(1, "\nPress enter to continue...\n", 28);
	read(0, buffer, 2);
	write(1, "\e8\e[0J", 7);
}

//Display precisely the line about the value store at this position
void	display_value(char *num, char symbol)
{
	int	num_len;

	num_len = fn_strlen(num) + 1;
	write(1, "\nValue is: ", 12);
	write(1, &symbol, 1);
	write(1, " / ", 3);
	write(1, num, num_len);
}

//Get the value of a user input and store it at 
//current cursor position in the grid
void	fn_getchar(int *playground, int *cursor, char *file)
{
	int		value;
	char	*buffer;

	write(1, "\e7", 3);
	value = 255;
	buffer = malloc(1);
	if (buffer == NULL)
		free_all_error(file, playground, "CICR");
	write(1, "\nPlease enter an ascii character:\n", 34);
	read(0, buffer, 1);
	write(1, "\e8\e[0J", 7);
	value = buffer[0];
	free(buffer);
	playground[*cursor] = value;
}

//Display the character equivalent to current cursor pos
//in grid stored value
void	put_char(int value)
{
	char	to_print;

	to_print = (char) value;
	write(1, &to_print, 1);
}

//Manage the logic of while loops in brainfuck
void	start_while(char *file, int *pos, int *playground, int *cursor)
{
	int	start;

	start = *pos;
	++*pos;
	while (file[*pos] != 0)
	{
		if (file[*pos] == ']' && playground[*cursor] != 0)
			*pos = start;
		else if (file[*pos] == ']' && playground[*cursor] == 0)
			break ;
		else if (file[*pos] == '+' || file[*pos] == '-'
			|| file[*pos] == '>' || file[*pos] == '<')
			input_to_action(file[*pos], playground, cursor);
		else
			parsing_complex(file, pos, playground, cursor);
		++*pos;
	}
	--*pos;
}
