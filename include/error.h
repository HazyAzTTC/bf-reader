/* ************************************************************************** */
/*                                                                            */
/*                                                        ==     +:           */
/*   error.h                                               -=   +-:           */
/*                                                        ==-  .===           */
/*   By: hazy_az <coding.hazyaz@proton.me>                *=*:::++*-..        */
/*                                                        =+*=+:=**---.       */
/*   Created: 2026/01/28 00:13:20 by hazy_az              .:=#**+--=**++:     */
/*   Updated: 2026/02/10 14:01:50 by hazy_az             .:-#=-+*==**+-..     */
/*                                                       ..-=+==+=+--:..      */
/*                                                       ...-===+==--::-:.    */
/*                                                        .-:-===*+=----.     */
/*                                                       .:--==+=++*#:--:.    */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error(char *error_code);
void	free_all_error(char *st_free, int *ar_free, char *error_code);
void	free_char_error(char *to_free, char *error_code);
void	free_close_error(char *to_free, int to_close, char *error_code);
void	free_int_error(int *to_free, char *error_code);

#endif
