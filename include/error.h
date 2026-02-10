/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   error.h                                               -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 00:13:20 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/10 01:43:22 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error(char *error_code);
void	free_all_error(char *to_free, char *error_code);
void	free_char_error(char *to_free, char *error_code);
void	free_int_error(int *to_free, char *error_code);

#endif
