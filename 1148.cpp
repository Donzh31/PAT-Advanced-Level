#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	int N;
	int input[101];

	int tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		input[i + 1] = tmp;
		
	}
	int lie_wolf, lie_farmer;
	int flag = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			lie_wolf = lie_farmer = 0;
			for (int k = 1; k <= N; k++)
			{
				if(k==i || k==j)
				{
					if (input[k] >= 0 && (input[k] == i || input[k] == j))
						lie_wolf++;
					else if (input[k] < 0 && input[k] != -i && input[k] != -j)
						lie_wolf++;
				}
				else
				{
					if (input[k] >= 0 && (input[k] == i || input[k] == j))
						lie_farmer++;
					else if (input[k] < 0 && input[k] != -i && input[k] != -j)
						lie_farmer++;
				}
			}
			if (lie_wolf == 1 && lie_farmer == 1)
			{
				cout << i << " " << j << endl;
				flag = 1;
				break;
			}
				
		}
		if (flag)
			break;
	}
	if (!flag)
		cout << "No Solution" << endl;
	
}