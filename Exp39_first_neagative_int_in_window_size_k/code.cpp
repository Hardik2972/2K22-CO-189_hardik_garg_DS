#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> printFirstNegativeInteger(long long A[], long long N, long long k) {
    vector<long long> ans;
    queue<long long> q;

    for (long long i = 0; i < k - 1; i++) {
        if (A[i] < 0) q.push(A[i]);
    }
    for (long long i = k - 1; i < N; i++) {
        if (A[i] < 0) q.push(A[i]);
        if (A[i - k] < 0) q.pop();
        if (q.empty()) ans.push_back(0);
        else ans.push_back(q.front());
    }
    return ans;
}

int main() {
    long long N, k;
    cin >> N >> k;
    long long A[N];

    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> result = printFirstNegativeInteger(A, N, k);

    for (long long i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
