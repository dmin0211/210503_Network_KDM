#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[210];
bool visit[210];
int answer_count;

void bfs(int i){
  queue<int> q;
  q.push(i);
  visit[i]=true;

//  cout<<i<<endl;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    for (int j = 0; j < edge[current].size(); ++j) {
      int next = edge[current][j];
//      cout<<current<<"->"<<next<<endl;
      if(!visit[next]){
        visit[next]=true;
        q.push(next);
      }
    }
  }
  answer_count++;
}

int all_visit(int n){
  for (int i = 0; i < n; ++i) {
    if(visit[i]==false) return i;
  }
  return -1;
}

int solution(int n, vector<vector<int>> computers) {
  for (int i = 0; i < computers.size(); ++i) {
    for (int j = 0; j < computers[i].size(); ++j) {
      if(i==j) continue;
      if(computers[i][j]==1) {
        edge[i].push_back(j);
        edge[j].push_back(i);
      }
    }
  }
  memset(visit,false,210);
  int false_index= all_visit(n);
  while(false_index!=-1){
    bfs(false_index);
//    for (int i = 0; i < n; ++i) {
//      cout<<visit[i]<<"\t";
//    }cout<<endl;
    false_index= all_visit(n);
  }
  return answer_count;
}

int main() {
  cout<<solution(5, {{1,0,0,0,0},{0,1,0,0,1},{0,0,1,0,1},{0,0,0,1,1},{1,0,0,0,1}})<<endl;
}