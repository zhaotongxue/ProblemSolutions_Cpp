#include <cstring>
#include <iostream>
const char *res[] = {"You win.", "You lose.", "You chickened out."};
char fir[105], sec[105];
int ifir[26], isec[26];
bool finished()
{
	for (int i = 0; i < 26; i++) {
		if (ifir[i] == 1) return false;
	}
	return true;
}
int main()
{
	int round = 0;
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	while ((std::cin >> round) && round > 0) {
		memset(ifir, 0, sizeof(ifir));
		memset(isec, 0, sizeof(isec));
		std::cin >> fir >> sec;
		for (int i = 0; i < strlen(fir); i++) {
			ifir[fir[i] - 'a'] = 1;
		}
		int steps = 0;
		for (int i = 0; i < strlen(sec); i++) {
			if (ifir[sec[i] - 'a'] == 2) continue;
			if (ifir[sec[i] - 'a'] == 0) {
				steps++;
				if (steps == 7) break;
			}
			ifir[sec[i] - 'a'] = 2;
			if (finished()) break;
		}
		// bool finish = 1;
		// for (int i = 0; i < 26; i++) {
		// 	if (isec[i] == 1 && ifir[i] == 0) {
		// 		steps++;
		// 		if (steps >= 7) break;
		// 	}
		// 	if (ifir[i] == 1 && isec[i] == 0) {
		// 		finish = 0;
		// 		// break;
		// 	}
		// }
		std::cout << "Round " << round << std::endl;
		if (steps >= 7)
			std::cout << res[1] << std::endl;
		else if (finished())
			std::cout << res[0] << std::endl;
		else
			std::cout << res[2] << std::endl;
	}
	return 0;
}