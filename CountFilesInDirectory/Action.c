//Devendra Singh has written the below code to count the number of files in a Directory.
//System and Dir commands are used to get the count.

Action()
{

	char command[1024];
	
	//The file dircount will be created in script folder and will contain the details of C drive of system on which script is executed.
	sprintf(command, "dir c: >> dircount.txt");
	lr_output_message("The command is %s",command);
	system(command);

	return 0;
}

