#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    int fresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                visited[i][j] = 1;
                q.push({{i, j}, 0});
            }
            if (grid[i][j] == 1)
            {
                fresh++;
            }
        }
    }

    // now apply bfs
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {-1, 0, 1, 0};
    int time = 0;
    while (!q.empty())
    {
        int t = q.front().second;
        int x = q.front().first.first;
        int y = q.front().first.second;
        time = t;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = x + dr[i];
            int nc = y + dc[i];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                q.push({{nr, nc}, t + 1});
                visited[nr][nc] = 1;
                fresh--;
            }
        }
    }
    return fresh == 0 ? time : -1;
}
int main(){
    vector<vector<int>> grid = { {2,1,1}, { 1, 1, 0 }, { 0, 1, 1 } };
    cout << "minimum no. of minutes :" << orangesRotting(grid) << endl;
    return 0;
}