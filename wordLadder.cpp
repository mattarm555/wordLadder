#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

//Implement breadth-first search, refer to Lab 10

void buildGraph(unordered_map<string, vector<string>> &adj) {
  unordered_map<string, vector<string>> buckets;

  for (const string &word : V) {
    for (int i = 0; i < 5; i++) {
      string pattern = word;
      pattern[i] = '*'; 
      buckets[pattern].push_back(word);
    }
  }
  for (auto &b : buckets) {
    const vector<string> &group = b.second;
    for (size_t i = 0; i < group.size(); i++) {
      for (size_t j = i + 1; j < group.size(); j++) {
        adj[group[i]].push_back(group[j]);
        adj[group[j]].push_back(group[i]);
      }
    }
  }
}

void bfs(const string &start, const string &target,
         unordered_map<string, string> &pred,
         unordered_map<string, int> &dist,
         unordered_map<string, vector<string>> &adj)
         {
          queue<string> q;
          q.push(start);
          dist[start] = 0;

          while (!q.empty()) {
              string curr = q.front();
              q.pop();
          for (const string &neighbor : adj[curr]) {
            if (dist.find(neighbor) == dist.end()) {
                dist[neighbor] = dist[curr] + 1;
                pred[neighbor] = curr;
                q.push(neighbor);

                if (neighbor == target) {
                    return; 
                }
            }
        }
    }
}

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  //Implement this function
  steps = 0;
  p.clear();

  if (V.empty()) {
    ifstream fin("wordlist05.txt");
    string word;
    while (fin >> word) {
      if (word.size() == 5) {
        V.push_back(word);
      }
    }
  }
    bool foundS = false; 
    bool foundT = false;
    for (auto &w : V) {
      if (w == s) foundS = true;
      if (w == t) foundT = true;
    }
    if (!foundS || !foundT) {
      return; 
    }
    if (s == t) {
      return;
    }
    unordered_map<string, vector<string>> adj;
    buildGraph(adj);
    unordered_map<string, int> dist;
    unordered_map<string, string> pred;
    bfs(s, t, pred, dist, adj);
    if (dist.find(t) == dist.end()) {
      steps = 0;
      return; 
  }
  vector<string> path;
  string curr = t;
  while (curr != s) {
    path.push_back(curr);
    curr = pred[curr]; 
}
  path.push_back(s);
  reverse(path.begin(), path.end());
  steps = path.size() - 1;
  p = path;
 }

/*
int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
*/