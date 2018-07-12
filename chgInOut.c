// Running on file named f

// file description table
// 0 = standard input
// 1 = standard output
// 2 = standard error
// n1 = input.txt

// Input redirection -> $ ./f < input.txt

if (n1 = open("input.txt", O_RDONLY) < 0)
	exit(-1); 	
close(0); 			// invalidates standard input		
dup(n1);  			// Duplicates n1, places in first available slot (0);
close(n1);			// ** With system call, an entry will be added **
execl("ls", ...);	
	
// Output redirection -> $ ./f > output.txt

if (n1 = creat("input.txt", 0754) < 0)
	exit(-1);
close(1); 			// invalidates standard output
dup(n1);			// duplicates n1, places into first available slot (1)
close(n1);			// close n1
execl("ls", ...);	// execute.

// Both -> $ ./f < input.txt > output.txt

*/ Do input redirection and output redirection both /*