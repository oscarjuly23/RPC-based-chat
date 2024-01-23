/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h>
#include "basedChat.h"

int *
write_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

	char *filename = "Chat.txt";

	// open the file for writing
    FILE *fp = fopen(filename, "a");
	if (fp == NULL) {
        printf("Error opening the file %s", filename);
        return 0;
    }


	// write to the text file
	fprintf(fp, "%s", *argp);
	
	// close the file
    fclose(fp);

	printf("SERVER: Message recived and writed to the file\n");

   	result = 1;

	return &result;
}

char **
getchat_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	char *filename = "Chat.txt";

	// open the file for reading
    FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
        printf("Error opening the file %s", filename);
		return NULL;
    }

	/* Seek to the beginning of the file */
   	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	result = (char*)calloc(fsize, sizeof(char));

	// read the text file
	fread(result, sizeof(char), fsize, fp);

	// close the file
    fclose(fp);

	//printf("SERVER: Send entire chat to Client\n");

	return &result;
}
