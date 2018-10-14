//Devendra Singh has written the below code to create a unique filename using timestamp till milliseconds
//Structure has been used in script to define the time till milliseconds.
//A file will be created with name similar to "File_10132018_225427_929" in the scripts folder on execution

typedef long time_t;
struct timeb
{
	time_t time;
	unsigned short millitm;
};

struct tm
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
};


long outstream = 0;
char OutputFile[1024] = "";	

Action()
{
	
	struct timeb tb;
	struct tm * now;
	char FileName[256];
	_tzset(); // Set variables used by localtime
	ftime(&tb); // current timestamp
	now = (struct tm *)localtime(&tb.time);
	sprintf(FileName, "%02d%02d%04d_%02d%02d%02d_%03u",
		now->tm_mon + 1,
		now->tm_mday,
		now->tm_year + 1900,
		now->tm_hour,
		now->tm_min,
		now->tm_sec,
		tb.millitm
	);
	
	lr_output_message("File name is: %s", FileName);
	
	//Defining the file name with Timestamp till milliseconds as suffix
	sprintf(OutputFile,"File_%s.txt",FileName);
	
	//Opening the file in append mode
	outstream = fopen (OutputFile,"a+");
	
	if (outstream == NULL)
	lr_output_message ("Not able to open output file %s",OutputFile);
	
	//Writing to file
	else
	{
	fprintf (outstream, "The current iteration is %s, at %s. \r\n",
	lr_eval_string("{Iteration}"),
	FileName);
	fclose (outstream);
	}
	
	return 0;
}