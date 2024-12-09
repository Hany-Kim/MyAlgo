#include <iostream>

using namespace std;

int N, M;

int main(void) {
    cin >> N >> M;
    
    for(int y=0; y<M; ++y){
        for(int x=0; x<N; ++x){
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}