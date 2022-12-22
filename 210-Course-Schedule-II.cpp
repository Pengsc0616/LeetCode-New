class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // course -> pre-course
        vector<Node*> courses;
        for(int i=0; i<numCourses; i++) courses.push_back(new Node(i));
        for(const auto & rule: prerequisites) {
            courses[rule[0]]->preCourses.push_back(rule[1]);
        }
        V = vector<bool>(numCourses, false);
        visiting = vector<bool>(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            if(!V[i]) if(!dfs(i, courses)) return {};
        }
        return ans;
    }
private:
    vector<bool> V;
    vector<bool> visiting;
    vector<int> ans;
    class Node {
    public:
        Node(int id) {this->id = id;}
        int id;
        vector<int> preCourses;
    };
    bool dfs(int id, vector<Node*> & courses) {
        if(visiting[id]) return false;
        if(V[id]) return true;
        visiting[id] = true;
        V[id] = true;
        for(const auto & preCourse: courses[id]->preCourses) {
            // if(V[preCourse]) continue;
            if(!dfs(preCourse, courses)) return false;
        }
        ans.push_back(id);
        visiting[id] = false;
        return true;
    }
};










