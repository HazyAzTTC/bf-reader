# bf-reader
*Homemade, from scratch, with fewer libs possible (and built-in only) brainfuck interpreter in C... trying to improve skills*

## QUICK HOW TO USE

It's a terminal program so launch it from terminal.<br>
If you took the source code, if you are on Linux, just use the [Makefile](./MAKEDOC.md). Else, I don't know, GLHF.<br>
When prompted enter the path to the file containing your Brainfuck code.<br>
Then it will read and execute your Brainfuck code. Prompting you and displaying debug info when the code say so.<br>
For debug info you'll have to execute program with the "debug" argument and you code must contain the # character where you want info.<br>
<br>
More information about brainfuck language [here](https://en.wikipedia.org/wiki/Brainfuck).

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

List of error code with where it happens in code and definition:<br><br>
	-**CGFS** ==> Can't Get File Size   *(file_utils.c/sizing)*<br>
			The open() in the sizing function failed to open the file you've precised.<br><br>
	-**CICR** ==> Can't Initialise Character Retriever   *(complex_inputs.c/fn_getchar)*<br>
			Malloc failed to create the holder variable for getting char from user.<br><br>
	-**CIFR** ==> Can't Initialise File Reader   *(core.c/getting_file)*<br>
			Malloc failed to create the var that will store your bf code.<br><br>
	-**EWTD** ==> Error While Trying to Debug   *(debug_treating.c/fn_itoa)*<br>
			Malloc failed to create the str to display a number.<br><br>
	-**FCBF** ==> File Can't Be Found   *(core.c/getting_file)*<br>
			The open() in getting_file failed to open the file you've precised.<br><br>
	-**FCDR** ==> Fail to Create Debug Remover   *(debug_treating.c/anti_debug)*<br>
			Malloc failed to create the var that store your bf code without the # character.<br><br>
	-**FIGM** ==> File to Initialise Grid Malloc   *(core.c/grid_init)*<br>
			Malloc failed to create the array where your bf code should be executed.<br><br>
	-**NEAL** ==> Not Enough Arguments at Launch   *(main.c/arg_nb_verif)*<br>
			Program has been launched with 0 arguments (the program basic execution should make it at least 1).<br><br>
	-**PVCI** ==> Path Variable Can't be Initialise   *(main.c/get_path)*<br>
			Malloc failed to create the var storing the path of your bf code file.<br><br>
	-**TMAL** ==> Too Many Arguments at Launch   *(main.c/arg_nb_verif)*<br>
			Programm has been launche with more than 2 arguments (the program basic execution + default/debug mode makes it two).<br><br>

## AFTERWORDS

Well this is just a project for getting more at ease with C languages (with pretty rude conditions?) and joking with a friend.<br>
If you want to use it, please help yourself, thank you, but to be fair I'll be surprised.<br>
If you want to send me feedbacks, advice or criticism, I'm open to it as long as it's done in a civilised way (respecting other is respecting yourself)<br><br>
Big thank you and shoutout to [@newgendaire2](https://github.com/newgendaire2) for being a very good friend even when I'm difficult and to be a funny chaotic human being!<br><br>
Anyway, thank you, take care and stay hazy~~ <br><br>
-Hazy_Az
