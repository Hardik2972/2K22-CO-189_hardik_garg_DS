#include <iostream>

using namespace std;
// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function
    void toi(int N,int from,int to,int aux, long long &count){
        if(N==0){
            return;
        }
        toi(N-1,from,aux,to,count);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        count++;
        toi(N-1,aux,to,from,count);
    }
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        long long count = 0;
        toi(N,from,to,aux,count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}
