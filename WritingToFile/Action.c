//Devendra Singh has written the below code to write Time, Date and Iteration count to a file.
//DateTime, fopen, fprinf and fclose functions are used in this script.
//A file will be created with name similar to "Write_To_File_13Oct2018" in the scripts folder on execution

long outstream = 0;
char OutputFile[1024] = "";		

Action()
{
	lr_save_datetime("%d%b%Y", DATE_NOW, "FileDate"); 
	lr_save_datetime("%d/%b/%Y", DATE_NOW, "Date"); 
	lr_save_datetime("%H:%M:%S %p", TIME_NOW, "Time"); 
	
	//Defining the file name with current date as suffix
	sprintf(OutputFile,"Write_To_File_%s.txt",
	lr_eval_string("{FileDate}"));
	
	//Opening the file in append mode
	outstream = fopen (OutputFile,"a+");
	
	if (outstream == NULL)
	lr_output_message ("Not able to open output file %s",OutputFile);
	
	//Writing to file
	else
	{
	fprintf (outstream, "The current iteration is %s, at %s on %s. \r\n",
	lr_eval_string("{Iteration}"),
	lr_eval_string("{Time}"),
	lr_eval_string("{Date}"));
	fclose (outstream);
	}
	
	return 0;
}
