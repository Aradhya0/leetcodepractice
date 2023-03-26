/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    int checkifAllSame(vector<vector<int>>& grid, int ri, int rj, int ci, int cj) {

        int val = grid[ri][ci];

        for (int i=ri; i<=rj;i++) {
            for (int j=ci;j<=cj;j++) {
                if (grid[i][j]!=val){
                    return -1;
                }
            }
        }

        return val;

    }

    Node* construct(vector<vector<int>>& grid, int ri, int rj, int ci, int cj) {

        if (ri==rj && ci==cj) {
            return new Node(grid[ri][ci], true);
        }
        int isAllSame = checkifAllSame(grid, ri, rj, ci, cj);
        if (isAllSame!=-1) {
            return new Node(isAllSame, true);
        }

        Node* head = new Node(1, false);

        head->topLeft = construct(grid, ri, (ri+rj)/2, ci, (ci+cj)/2);
        head->topRight = construct(grid, ri, (ri+rj)/2, (ci+cj)/2+1, cj);
        head->bottomLeft = construct(grid, (ri+rj)/2+1, rj, ci, (ci+cj)/2);
        head->bottomRight = construct(grid, (ri+rj)/2+1, rj, (ci+cj)/2+1, cj);

        return head;

    }

public:
    Node* construct(vector<vector<int>>& grid) {

        return construct(grid, 0, grid.size()-1, 0, grid[0].size()-1);
        
    }
};
