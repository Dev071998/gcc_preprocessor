This is the basic implimentation of gcc pre processor. 

Creat a pre-processor which executed with input file in command line argument.

The fname.c is considered to be a source file and after process completion should generate the gile name fname.i, which is the extended source code.

specification:

1. Remove all comments 
   > Either remove the comments
2. File Inclusion
	If "#include" string found, then copy the body of the file named inside the < > or " ", replacing the #include statement.

3. Macro substitution
	if "#define" string found, then replace every MACRO in the file with the macro body.




what is pre-processor?
 
Pre-processor is a firlst stage of compilation. We provide fname.c and after this stage it will return fname.i file. In fname.i file all comments are removed, header files included, macro replaced with there body and pre-processor do condition compilation with the help of condition compilaton we can write more then one main fnction in same code. Using condition complation we reduce the size of executable code. 

command:
cc -E fname.c -o fname.i

Note: Pre-processor does not change the fname.c file it will copy that file data into fname.i file and process it.
