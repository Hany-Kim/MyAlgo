#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int k, int d) {
	long long answer = d / k + 1;

	/*long long cnt = 0;
	for (long long y = 0; y <= d; y += k) {
		for (long long x = 0; x <= d; x += k) {
			long long dist = pow(y, 2) + pow(x, 2);
			if (dist <= pow(d, 2)) cnt += 1;
		}
	}

	answer = cnt;*/

	long long cnt = 0;
	for (long long y = 0; y < d; y += k) {
		long long s = 1;
		long long e = d;
		int ptr = 0;
		while (s <= e) {
			int mid = (s + e) / 2;

			if (pow(mid, 2) + pow(y, 2) <= pow(d, 2)) {
				s = mid + 1;
				ptr = mid;
			}
			else e = mid - 1;
		}

		cnt += (ptr / k);
	}

	answer += cnt;

	return answer;
}