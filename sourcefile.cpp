#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int root[210];
int uf_rank[210];
int N;

int find_union(int a){
  if(root[a]==a){
    return a;
  } else {
    return root[a]=find_union(root[a]);
  }
}

void set_union(int a, int b) {
  int x = find_union(a);
  int y = find_union(b);
  if(x==y) return;
  if(uf_rank[x] < uf_rank[y]){
    root[x] = y;
  }else{
    root[y] = x;
    if(uf_rank[x]==uf_rank[y]){
      uf_rank[x]++;
    }
  }

}

int solution(int n, vector<vector<int>> computers) {
  for (int i = 0; i < n; ++i) {
    root[i]=i;
  }
  for (int i = 0; i < computers.size(); ++i) {
    for (int j = 0; j < computers[i].size(); ++j) {
      if(computers[i][j]==1 ) set_union(i,j);
    }
  }
  vector<int> size_answer;
  for (int i = 0; i < n; ++i) {
    if(find(size_answer.begin(),size_answer.end(),find_union(i))==size_answer.end())
      size_answer.push_back(find_union(i));
  }
  return size_answer.size();
}

int main() {
  cout<<solution(5, {{1,0,0,0,0}, {0,1,0,0,1}, {0,0,1, 0, 1}, {0,0,0,1,1},{1,0,0,0,1}})<<endl;
}