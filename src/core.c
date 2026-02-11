/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   core.c                                                -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:51:05 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/11 18:47:53 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "complex_inputs.h"
#include "debug_treating.h"
#include "error.h"
#include "file_utils.h"

//Try to create the BF array. Close program on fail.
int	*grid_init(char *file)
{
	int	*grid;
	int	index;

	index = 0;
	grid = malloc(8 * 30000);
	if (grid == NULL)
		free_char_error(file, "FIGM");
	while (index < 29999)
	{
		grid[index] = 255;
		++index;
	}
	while (index >= 0)
	{
		grid[index] = 0;
		--index;
	}
	return (grid);
}

//Check if file exists, if so take size of file then stock content in var
char	*getting_file(char *path)
{
	int		file_channel;
	int		file_size;
	char	*file;

	file_size = sizing(path);
	file_channel = open(path, O_RDONLY);
	if (file_channel == -1)
		free_close_error(path, file_channel, "FCBF");
	free(path);
	file = malloc(file_size);
	if (file == NULL)
	{
		close(file_channel);
		error("CIFR");
	}
	read(file_channel, file, file_size);
	close(file_channel);
	file[file_size] = '\0';
	return (file);
}

//Parse input and redirect || edit datas accordingly.
void	input_to_action(char input, int *playground, int *cursor)
{
	if (input == '>' && *cursor < 29999)
		++*cursor;
	else if (input == '>' && *cursor == 29999)
		*cursor = 0;
	else if (input == '<' && *cursor > 0)
		--*cursor;
	else if (input == '<' && *cursor == 0)
		*cursor = 29999;
	else if (input == '+' && playground[*cursor] < 255)
		playground[*cursor]++;
	else if (input == '+' && playground[*cursor] == 255)
		playground[*cursor] = 0;
	else if (input == '-' && playground[*cursor] > 0)
		playground[*cursor]--;
	else if (input == '-' && playground[*cursor] == 0)
		playground[*cursor] = 255;
	return ;
}

//Get file content and make it go through interpreter
void	interpret_file(char *path, int debug)
{
	int		cursor;
	int		*grid;
	int		track;
	char	*file;

	cursor = 0;
	track = 0;
	file = getting_file(path);
	if (debug == 0)
		file = anti_debug(file);
	grid = grid_init(file);
	while (file[track])
	{
		if (file[track] == '>' || file[track] == '<'
			|| file[track] == '+' || file[track] == '-')
			input_to_action(file[track], grid, &cursor);
		else
			parsing_complex(file, &track, grid, &cursor);
		track++;
	}
	free(file);
	free(grid);
	write(1, "\n\n\033[0;32mEOF & EOP\033[0m\n", 24);
	return ;
}

//Parsing more complex inputs
void	parsing_complex(char *file, int *pos, int *playground, int *cursor)
{
	if (file[*pos] == '[')
		start_while(file, pos, playground, cursor);
	else if (file[*pos] == ',')
		fn_getchar(playground, cursor, file);
	else if (file[*pos] == '.')
		put_char(playground[*cursor]);
	else if (file[*pos] == '#')
		debug_print(playground, cursor, file);
	return ;
}
