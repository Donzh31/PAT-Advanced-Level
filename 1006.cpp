#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int num;
	char id_in[20];
	char id_out[20];
	char min_sign_in[20] = "23:59:59";
	char max_sign_out[20] = "00:00:00";
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		char tmp_id[20];
		char tmp_in[20];
		char tmp_out[20];
		scanf("%s%s%s", tmp_id, tmp_in, tmp_out);
		if (strcmp(tmp_in, min_sign_in) < 0)
		{
			strcpy(min_sign_in, tmp_in);
			strcpy(id_in, tmp_id);
		}
		if (strcmp(tmp_out, max_sign_out) > 0)
		{
			strcpy(max_sign_out, tmp_out);
			strcpy(id_out, tmp_id);
		}
	}
	printf("%s %s", id_in, id_out);


}