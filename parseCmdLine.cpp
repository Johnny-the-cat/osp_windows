#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

int parseCmdLine(int argc, char* argv[], char *primarylogin, char *primarypass, char *primarydblink, char *standbylogin, char *standbypass, char *standbydblink, char *pathparameter)
{
	const char *usage = "Usage: osp primary=login/pass@server standby=login/pass@server primarylike|auto|autoforce|gennext|\"C:\\real\\path\"\n\"primarylike\" - the path for the datafile will remain the same as on the primary server\n\
\"auto\" - the directory for the datafile will be the same as the last one in this table space\n\"autoforce\" - the directory for the datafile will be the same as the last one in this tablespace. If there is no tablespace yet, the directory for the datafile will be the same as the SYSTEM tablespace\n\
\"gennext\" - the datafile name will be generated based on the previous one without connecting to the primary server\n\
C:\\real\\path - directory for the datafile\n\nosp version - 1.1.0\n";

	if (!(argc == 4 || argc == 3))
	{
		printf("%s\n", usage);
		//printf("Arguments count is %d\n", argc);
		exit(EXIT_FAILURE);
	}
	int i;

	int gotprimary = FALSE;
	int gotstandby = FALSE;
	int gotpathparameter = FALSE;

	for (i = 1; i < argc; i++)
	{
		if (strstr(argv[i], "primary=") == argv[i])
		{
			if (gotprimary == FALSE)
			{
				char *slashpointer, *atpointer;
				int connectlinelen;
				char connectline[256];

				strncpy(connectline, argv[i] + (int)strlen("primary="), 256);
				connectlinelen = strlen(connectline);
				//printf("Connect line lengh - %d\n", connectlinelen);

				slashpointer = strchr(connectline, '/');
				atpointer = strchr(connectline, '@');
				if ((slashpointer - connectline) == 0 || *(connectline) == '/')
				{
					printf("Primary login is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if (slashpointer == NULL || (atpointer - slashpointer - 1) == 0)
				{
					printf("Primary pass is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if (atpointer == NULL || (connectlinelen - (atpointer - connectline) - 1) == 0)
				{
					printf("Primary dblink is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if ((slashpointer - connectline) > 30)
				{
					printf("Primary login is too large\n");
					exit(EXIT_FAILURE);
				}

				if (atpointer - slashpointer - 1 > 30)
				{
					printf("Primary pass is too large\n");
					exit(EXIT_FAILURE);
				}

				if ((connectlinelen - (atpointer - connectline) - 1) > 127)
				{
					printf("Primary dblink is too large\n");
					exit(EXIT_FAILURE);
				}

				strncpy(primarylogin, connectline, slashpointer - connectline);

				strncpy(primarypass, slashpointer + 1, atpointer - slashpointer - 1);

				strncpy(primarydblink, atpointer + 1, connectlinelen - (atpointer - connectline) - 1);

				gotprimary = TRUE;
				//printf("primarylogin - %s\n", primarylogin);
				//printf("primarypass - %s\n", primarypass);
				//printf("primarydblink - %s\n", primarydblink);
				continue;

			}
			else
			{
				printf("Argument \"primary\" is already got\n");
				printf("%s\n", usage);
				exit(EXIT_FAILURE);
			}
		}

		else if (strstr(argv[i], "standby=") == argv[i])
		{
			if (gotstandby == FALSE)
			{
				char *slashpointer, *atpointer;
				int connectlinelen;
				char connectline[256];

				strncpy(connectline, argv[i] + (int)strlen("standby="), 256);
				connectlinelen = strlen(connectline);
				//printf("Connect line lengh - %d\n", connectlinelen);

				slashpointer = strchr(connectline, '/');
				atpointer = strchr(connectline, '@');
				if ((slashpointer - connectline) == 0 || *(connectline) == '/') {
					printf("Standby login is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if (slashpointer == NULL || (atpointer - slashpointer - 1) == 0) {
					printf("Standby pass is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if (atpointer == NULL || (connectlinelen - (atpointer - connectline) - 1) == 0) {
					printf("Standby dblink is not found\n");
					printf("%s\n", usage);
					exit(EXIT_FAILURE);
				}

				if ((slashpointer - connectline) > 30) {
					printf("Standby login is too large\n");
					exit(EXIT_FAILURE);
				}

				if (atpointer - slashpointer - 1 > 30) {
					printf("Standby pass is too large\n");
					exit(EXIT_FAILURE);
				}

				if ((connectlinelen - (atpointer - connectline) - 1) > 127) {
					printf("Standby dblink is too large\n");
					exit(EXIT_FAILURE);
				}

				strncpy(standbylogin, connectline, slashpointer - connectline);

				strncpy(standbypass, slashpointer + 1, atpointer - slashpointer - 1);

				strncpy(standbydblink, atpointer + 1, connectlinelen - (atpointer - connectline) - 1);

				gotstandby = TRUE;
				//printf("standbylogin - %s\n", standbylogin);
				//printf("standbypass - %s\n", standbypass);
				//printf("standbydblink - %s\n", standbydblink);
				continue;
			}

			else
			{
				printf("Argument \"standby\" is already got\n");
				printf("%s\n", usage);
				exit(EXIT_FAILURE);
			}
		}

		else
		{
			if (gotpathparameter == FALSE)
			{
				strncpy(pathparameter, argv[i], 256);
				gotpathparameter = TRUE;
				//printf("Path parameter - %s\n", pathparameter);
				continue;

			}
			else
			{
				printf("Argument \"pathparameter\" is alredy got\n");
				printf("%s\n", usage);
				exit(EXIT_FAILURE);
			}
		}
	}

	if (gotprimary == FALSE)
	{
		printf("Argument primary is missed\n");
		exit(EXIT_FAILURE);
	}

	if (gotprimary == FALSE && strcmp(pathparameter, "gennext") != 0)
	{
		printf("Argument primary is missed\n");
		exit(EXIT_FAILURE);
	}

	if (gotpathparameter == FALSE)
	{
		printf("Path parameter is missed\n");
		exit(EXIT_FAILURE);
	}

	return TRUE;
}