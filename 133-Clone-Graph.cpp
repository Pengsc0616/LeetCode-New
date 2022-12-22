/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        for(int i=0; i<=100; i++) nodePairList.push_back({new Node(i), false});
        dfs(node, 1);
        return nodePairList[1].first;
    }
private:
    vector<pair<Node*, bool>> nodePairList;
    void dfs(Node* node, int index) {

        if(node == NULL) return;
        if(nodePairList[index].second) return;
        nodePairList[index].second = true;
        for(const auto & neigh: node->neighbors) {
            nodePairList[index].first->neighbors.push_back(nodePairList[neigh->val].first);
            if(nodePairList[neigh->val].second) continue;
            dfs(neigh, neigh->val);
        }
    }
};

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(node == NULL) return NULL;
//         for(int i=0; i<=100; i++) nodePairList.push_back({new Node(i), false});
//         cout << node->val << endl;
//         dfs(node, nodePairList[1]);
//         return nodePairList[1].first;
//     }
// private:
//     vector<pair<Node*, bool>> nodePairList;
//     void dfs(Node* node, pair<Node*, bool> newNodePair) {
//      /*
//         不能這樣用pair<Node*, bool>帶入，因為這樣不會真的改變vector裡的東西
//          可以用pair<Node*, bool>&
//      */
//         if(node == NULL) return;
//         if(newNodePair.second) return;
//         newNodePair.second = true;
//         cout << "set " << newNodePair.first->val << " to true\n";
//         cout << newNodePair.first->val << endl;
//         for(const auto & neigh: node->neighbors) {
//             cout << "neight->val is " << neigh->val << endl;
//             newNodePair.first->neighbors.push_back(nodePairList[neigh->val].first);
//             if(nodePairList[neigh->val].second) {
//                 cout << nodePairList[neigh->val].first->val << " is true\n";
//                 continue;
//             }
//             dfs(neigh, nodePairList[neigh->val]);
//         }
//     }
// };

















