#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 모든 문자열을 소문자로 변환하는 헬퍼 함수 (도시 이름은 대소문자 구분을 하지 않으므로)
string to_lower_case(string s) {
    transform(s.begin(), s.end(), s.begin(), 
               [](unsigned char c){ return tolower(c); });
    return s;
}

int solution(int cacheSize, vector<string> cities) {
    // 1. 초기 실행 시간 및 엣지 케이스 처리
    int total_time = 0;

    // 캐시 크기가 0이면 모든 접근은 Cache Miss (시간 5)입니다.
    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    // 2. LRU 캐시 자료구조 초기화
    // cache_list: LRU 순서(가장 왼쪽이 LRU)를 유지하는 이중 연결 리스트
    //             std::list는 중간 삽입/삭제가 O(1)입니다.
    list<string> cache_list; 
    
    // cache_map: city 이름과, cache_list 내 해당 city의 iterator를 매핑하여
    //            O(1) 시간에 list 내 원소의 위치를 찾는 데 사용됩니다.
    unordered_map<string, list<string>::iterator> cache_map;

    // 3. 도시 배열 순차 처리
    for (string city : cities) {
        // 도시 이름은 대소문자 구분을 하지 않으므로 모두 소문자로 변환합니다.
        string lower_city = to_lower_case(city);

        // 3-1. Cache Hit (도시가 캐시에 존재하는 경우)
        if (cache_map.count(lower_city)) {
            total_time += 1; // 실행 시간 +1 (Hit)

            // LRU 규칙 적용: 해당 도시를 리스트에서 제거하고 가장 최근(MRU) 위치(앞)에 다시 삽입합니다.
            // 1. 기존 노드를 리스트에서 삭제
            cache_list.erase(cache_map[lower_city]); 
            
            // 2. 새로운 노드를 리스트의 맨 앞 (MRU)에 삽입
            cache_list.push_front(lower_city); 
            
            // 3. 맵의 iterator 갱신
            cache_map[lower_city] = cache_list.begin();

        } 
        // 3-2. Cache Miss (도시가 캐시에 존재하지 않는 경우)
        else {
            total_time += 5; // 실행 시간 +5 (Miss)

            // Cache Replacement (캐시가 가득 찬 경우)
            if (cache_list.size() == cacheSize) {
                // 1. LRU 항목 제거: 리스트의 맨 뒤 (가장 왼쪽, LRU) 항목을 삭제합니다.
                string lru_city = cache_list.back();
                cache_list.pop_back();
                
                // 2. 맵에서도 제거
                cache_map.erase(lru_city);
            }

            // New Item Addition
            // 1. 새로운 도시를 리스트의 맨 앞 (MRU)에 삽입
            cache_list.push_front(lower_city);
            
            // 2. 맵에 새로운 항목과 iterator를 추가/갱신
            cache_map[lower_city] = cache_list.begin();
        }
    }

    return total_time;
}

// // 테스트를 위한 main 함수 (옵션)
// int main() {
//     cout << "Test 1: " << solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl; // Expected: 50
//     cout << "Test 2: " << solution(3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}) << endl; // Expected: 21
//     cout << "Test 3: " << solution(2, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl; // Expected: 60
//     cout << "Test 4: " << solution(5, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}) << endl; // Expected: 52
//     cout << "Test 5: " << solution(2, {"Jeju", "Pangyo", "NewYork", "newyork"}) << endl; // Expected: 16 (Case-Insensitive check)
//     cout << "Test 6: " << solution(0, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl; // Expected: 25 (Cache Size 0)
//     return 0;
// }