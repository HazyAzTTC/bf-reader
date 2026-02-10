# bf-reader
*Homemade, from scratch, with fewer libs possible (and built-in only) brainfuck interpreter in C... trying to improve skills*

## QUICK HOW TO USE

For now? You can't, it's a WIP...

## METHODOLOGY NOTE

I used here (for the first time i think) a quick writing methodolgy so it's easier to navigate.<br>
If you have to check the code here how it works:<br><br>
	-Includes are declared following this order: first the matching .h file of current one in the /include dir (if exist), then built-in libs, then other .h files in the /include dir in use.<br><br>
	-Within the previous sorting of includes, they are sort by alphabetical order.<br><br>
	-Each function has a comment that describe it's purpose, only on .c file.<br><br>
	-Main function is always the one at the bottom of src/main.c .<br><br>
	-Functions are sort by type then by alphabetical order.<br><br>
	-Var that are not parameters are sort by type then alphabetical order.<br><br>
	-Type order is, from top to bottom, int then char then void. The exception being main(). I don't need other types for now so they are not in my methodology yet.<br><br>
	-If you're looking for a function you should look at headers. They should be in include/ .

## ERROR CODES

List before explanation (prototype):<br><br>
	-**CCSR** ==> Can't Change Size of the Reader   *(core.c/getting_file)*<br><br>
	-**CICR** ==> Can't Initialise Character Retriever   *(complex_inputs.c/get_char)*<br><br>
	-**CIFR** ==> Can't Initialise File Reader   *(core.c/getting_file)*<br><br>
	-**EWTD** ==> Error While Trying to Debug   *(debug_treating.c/fn_itoa)*<br><br>
	-**FCBF** ==> File Can't Be Found   *(core.c/getting_file)*<br><br>
	-**FCDR** ==> Fail Creating Debug Remover   *(debug_treating.c/anti_debug)*<br><br>
	-**FIGM** ==> File to Initialise Grid Malloc   *(core.c/grid_init)*<br><br>
	-**NEAL** ==> Not Enough Arguments at Launch   *(main.c/arg_nb_verif)*<br><br>
	-**PVCI** ==> Path Variable Can't be Initialise   *(main.c/get_path)*<br><br>
	-**TMAL** ==> Too Many Arguments at Launch   *(main.c/arg_nb_verif)*<br><br>

## AFTERWORDS

Well this is just a project for getting more at ease with C languages (with pretty rude conditions?)<br>
If you want to use it, please help yourself, thank you, but to be fair I'll be surprised.<br>
If you want to send me feedbacks, advice or criticism, I'm open to it as long as it's done in a civilised way (respecting other is respecting yourself)<br><br>
Anyway, thank you, take care and stay hazy~~ <br><br>
-Hazy_Az
