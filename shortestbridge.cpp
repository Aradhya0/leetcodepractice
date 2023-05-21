class Solution {
public:
    const vector<int> neighbors{-1, 0, 1, 0, -1};

    void dfs(int i, int j, int n, vector<vector<int>> &grid, queue<vector<int>> &q, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        q.push({i, j});

        for (int k = 0; k < 4; k++)
        {
            int new_i = i + neighbors[k];
            int new_j = j + neighbors[k + 1];

            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j] || grid[new_i][new_j] == 0)
                continue;

            dfs(new_i, new_j, n, grid, q, visited);
        }
    }

    int bfs(vector<vector<int>> &grid, queue<vector<int>> &q, vector<vector<bool>> &visited)
    {
        int n = grid.size();

        int distance = 0;

        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                vector<int> front = q.front();
                q.pop();

                int u_i = front[0];
                int u_j = front[1];

                for (int k = 0; k < 4; k++)
                {
                    int v_i = u_i + neighbors[k];
                    int v_j = u_j + neighbors[k + 1];

                    if (v_i < 0 || v_i >= n || v_j < 0 || v_j >= n || visited[v_i][v_j])
                        continue;

                    if (grid[v_i][v_j] == 1)
                        return distance;

                    q.push({v_i, v_j});
                    visited[v_i][v_j] = true;

                }
            }

            distance++;
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        
        queue<vector<int>> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false));        

        bool found = false;

        for (int i = 0; i < n && !found; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                dfs(i, j, n, grid, q, visited);
                found = true;
                break;
            }
        }        

        return bfs(grid, q, visited);
    }
};
