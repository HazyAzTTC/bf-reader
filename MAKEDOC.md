# bf-reader Makefile Doc
*Here the list and descriptions of all commands in the make file of the project*
<br><br><br><br>
-**make** : create objects files ending with .o from sources then create a test build executable file in bin/.<br><br>
-**make debug** : create objects files ending with .do from sources then create a debug build executable (compile with -g3 at the end) file in bin/<br><br>
-**make release** : create optimized objects files ending with .ro from sources then create an optimized release build (currently -O1) in the project's bin/ and if there already is one in directory, moves it the project's bin/.old/<br><br>
-**make install** : same as make release and then copying it in your /home/you/.local/bin/<br><br>
-**make clean** : delete objects files of make.<br><br><br>
-**make fclean** : same as make clean but also delete the executable made by make<br><br>
-**make dclean** : same as make clean but for make debug<br><br>
-**make dfclean** : same as make fclean but for make debug<br><br>
-**make rclean** : same as make clean but for make release<br><br>
-**make rfclean** : same as make fclean but for make release<br><br>
-**make iclean** : same as make rfclean but also delete the file created by make install<br><br>
-**make aclean** : do a make iclean, a make dfclean and a make fclean<br><br><br>
-**make re** : do a make fclean then a make<br><br>
-**make dre** : do a make dfclean then a make debug<br><br>
-**make rre** : do a make rfclean then a make release<br><br>
-**make ire** : do a make iclean then a make install
