#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int>parent;
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        vector<int> ans(2);
        parent.resize(edges.size()+1,-1);
        ans=detectCycle(edges);
        return ans;
    }
    
    
    void union_op(int from,int to){
        from=find(from);
        to=find(to);
        parent[from]=to;
    }
    
    int find(int v){
        if(parent[v]==-1) return v;
        else return find(parent[v]);
    }
    
    vector <int> detectCycle(vector<vector<int> >& edges){
        vector<int> ans(2);
        for(int i=0;i<edges.size();i++){
            if(find(edges[i][0])==find(edges[i][1])) {
            ans[0]=edges[i][0]; ans[1]=edges[i][1]; break;
            }
            else union_op(find(edges[i][0]),find(edges[i][1]));
        }
     return ans;
    }
    
    void printAnswer(vector<int> &ans){
    	cout << "[" << ans[0] << " " << ans[1] << "]" <<endl;
	}
};

int main(){
	Solution obj;
	int arr[5][2] = {{1,2},{2,3},{3,4},{1,4},{1,5}};
	vector<vector<int> > edges(5, vector<int> (2, 0));
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 2; ++j){
			edges[i][j] = arr[i][j];
		}
	}
	vector<int> ans	= obj.findRedundantConnection(edges);
	obj.printAnswer(ans);
	return 1;
}


//https://leetcode.com/problems/redundant-connection/
