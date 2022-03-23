#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
}

// bianary graph
bool isBipartite(vector< vector<int> >& graph) {
    if (graph.empty()) {
        return false;
    }
    set<int> a,b;
    for (int i = 0; i < graph.size(); ++i) {
        vector<int> tmpNodes = graph[i];
        if (a.empty()) {
            a.insert(i);
            for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
                b.insert(*iter);
            }
            continue;
        }

        // a has i node, so i belong to b
        if (a.find(i) != a.end()) {
            // so graph[i] nodes can not belong to b
            for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
                if (a.find(*iter) != a.end()) {
                    return false;
                } else {
                    b.insert(*iter);
                }
            }

            continue;
        }

        // a has not i nodes, but b has
        if (b.find(i) != b.end()) {
            for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
                if (b.find(*iter) != b.end()) {
                    return false;
                } else {
                    a.insert(*iter);
                }
            }

            continue;
        }

        // a and b both have not i nodes
        bool belong2a = true;
        for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
            if (a.find(*iter) != a.end()) {
                belong2a = false;
            }

            if (b.find(*iter) != b.end() && !belong2a) {
                return false;
            }
        }

        if (belong2a) {
            a.insert(i);
            for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
                b.insert(*iter);
            }
        } else {
            b.insert(i);
            for (vector<int>::iterator iter = tmpNodes.begin();iter != tmpNodes.end(); ++iter) {
                a.insert(*iter);
            }
        }

    }

    return true;
}
