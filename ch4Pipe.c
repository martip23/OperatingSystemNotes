// $ ls|more
// Second process will use output from first

// Parent process -> Child process
//   exec ls 			exec more

// A pipe is a special kind of file

// This is how the pipe is declared. Pipe has 2 sides. 
// Write end[1] -> Read end[0]
int fd[2];
pipe(fd); // A new entry will be made under label fd[0] & fd[1]
pid = fork(); // New process

if (pid < 0) { // ERROR
}
else if (pid > 0) { // Parent
	close(1);	// Closes the parents 
	dup(fd[1]);
	close(fd[1]);
	close(fd[0]);
	exec("ls", argv*);
}
else {		// Child (pid == 0)
	close(0);
	dup(fd[0]);
	close(fd[0]);
	close(fd[1]);
	exec("more", argv*);
}