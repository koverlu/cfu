#pragma once
namespace cfuFile
{
#ifdef WIN32
#include <string.h>
#include <io.h>
#include <direct.h>
//Check if all folders in the path are existed.
//If not, create them.
void MkDirs(const char *muldir)
{
	int i, len;
	char str[512];
	strncpy(str, muldir, 512);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '/' || str[i] == '\\')
		{
			char slash = str[i];
			str[i] = '\0';
			if (access(str, 0) != 0)
			{
				mkdir(str);
			}
			str[i] = slash;
		}
	}
	if (len > 0 && access(str, 0) != 0)
	{
		mkdir(str);
	}
	return;
}
#endif
}