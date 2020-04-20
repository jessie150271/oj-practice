#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * file1;
	FILE * file2;
	char * in = malloc(sizeof(char) * 1);
	for (int i = 2; i < argc; i = i + 1)
	{
		file1 = fopen(argv[1], "ab+");
		if (file1 == NULL)
		{
			printf("Can't not open the file '%s'", argv[1]);
			return 0;
		}
		file2 = fopen(argv[i], "rb");
		if (file2 == NULL)
		{
			printf("Can't not open the file '%s'", argv[i]);
			return 0;
		}

		while (!feof(file2))
		{
			if (fread(in, sizeof(char), 1, file2) == NULL) break;
			fwrite(in, sizeof(char), 1, file1);
		}
		if (file1 != NULL)fclose(file1);
		if (file2 != NULL)fclose(file2);
	}
	return 0;
}