/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   core.h                                                -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 17:53:17 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/09 02:48:09 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

int		*grid_init(void);
char	*getting_file(char *path);
void	input_to_action(char input, int *playground, int *cursor);
void	interpret_file(char *path);
void	parsing_complex(char *file, int *pos, int *playground, int *cursor);

#endif
