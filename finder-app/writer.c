#include<stdio.h>
#include<syslog.h>
#include<errno.h>
#include<string.h>



int main(int argc, char* argv[])
{
	openlog(NULL, LOG_PERROR | LOG_PID, LOG_USER);

	if( argc !=3 )
	{
		syslog(LOG_ERR, "2 arguments are required");
		closelog();
		return 1;
	}


	FILE *fp =fopen(argv[1], "w");
	if(fp == NULL)
	{
		syslog(LOG_ERR, "Could not open file %s: %s", argv[1], strerror(errno));
		closelog();
		return errno;
	}

	fprintf(fp, "%s", argv[2]);
	syslog(LOG_DEBUG, "Writing %s to file %s", argv[2], argv[1]);
	fclose(fp);
	closelog();

	return 0;

}

