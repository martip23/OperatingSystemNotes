for (j = 0; j <= pipes; j++) {
	if (pid>0)
	{
		if (j == 0) {
			// First child
		}
		if (j>0)
		{
			close(l_fd[0])
			close(l_fd[1])
		}
		l_fd[0] = r_fd[0];
		l_fd[1] = r_fd[1];
	}
}
if (pid==0) {



	exevp();
}