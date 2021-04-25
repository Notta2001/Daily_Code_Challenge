#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > criticalconnections;
int *visitedTimes;
int *lowTimes;
int time = 0;

void buildGraph(vector<vector<int> >& connections, int n,vector<vector<int> >& graph){
    for(int i = 0; i < connections.size(); ++i){
        int a = connections[i][0];
        int b = connections[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}
     
void dfs(int * visited , int curNode, int parentNode, int *visitedTimes ,vector<vector<int> >& graph ,int *lowTimes){
    visited[curNode] = 1;
    visitedTimes[curNode] = lowTimes[curNode] = time++;
        
    for(int i = 0; i < graph[curNode].size(); ++i){
        cout << graph[curNode][i] <<parentNode << endl;
        if(graph[curNode][i] == parentNode){
            continue;
        }
        if(visited[graph[curNode][i]] != 1){
            cout << 1;
            dfs(visited, graph[curNode][i],curNode, visitedTimes, graph, lowTimes);
            lowTimes[curNode] = min(lowTimes[curNode], lowTimes[graph[curNode][i]]);
            if(visitedTimes[curNode] < lowTimes[graph[curNode][i]]){
                vector<int> a;
                a.push_back(curNode);
                a.push_back(graph[curNode][i]);
                criticalconnections.push_back(a);
            }
        }
        else{
            lowTimes[curNode] = min(lowTimes[curNode], visitedTimes[graph[curNode][i]]);
        }
    }
}

vector<vector<int> > criticalConnections(int n, vector<vector<int> >& connections) {
    vector<vector<int> > graph(n);
    visitedTimes = new int[n];
    lowTimes = new int [n];
        
    // build an adjancency list for our graph
    buildGraph(connections,n, graph);
    int * visited = new int[n];
    dfs(visited, 0,-1, visitedTimes, graph, lowTimes);
    return criticalconnections;
}

int main(){
	vector<vector<int> > pub;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	vector<int> d;
	a.push_back(0);
	a.push_back(1);
	b.push_back(1);
	b.push_back(2);
	c.push_back(2);
	c.push_back(0);
	d.push_back(1);
	d.push_back(3);
	pub.push_back(a);
	pub.push_back(b);
	pub.push_back(c);
	pub.push_back(d);
	vector<vector<int> > res = criticalConnections(4, pub);
	for(int i = 0; i < res.size(); ++i){
		cout << "[" << res[i][0] << " " << res[i][1] << "]" << endl;
	}
	return 0;
}

/*1-1
100
20
111
01
30
111
2-1
[1 3]*/
