for execl;

$ls -al -t

execl("/bin/ls", "ls", "-al", "-t", 0);

execlp("ls", "ls", "-al", "-t", 0);

// for execv
char* args[20];
args[0] = 'ls';
argv[1] = '-al';
argv[2] = '-t';
argv[3] = '0';
execv("/bin/ls", args);

// for execve
char* argv[] = {'ls', '-al', '-t', 0};
char* env[] = {"HOME=/usr/home", "LOGNAME=home", 0}
execve("/bin/ls", args, env);