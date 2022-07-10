/*
Link:https://leetcode.com/problems/employee-importance/

This hierarchical structure reminds me of a tree and this question has the essence of number of nodes for any given node.
Instead of counting the nodes we need to get the total value contained by the root and its left and right subtree.

Here i used a graph to easily access each id's node
and then i used bfs to find the total sum of the importance of roots under the given node
*/


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> hash;
        for(int i=0;i<employees.size();i++)
        {
            hash[employees[i]->id]=i;
        }
        int count=0;
        queue<int> q;
        q.push(id);
        while(q.size())
        {
            Employee* temp = employees[hash[q.front()]];
            q.pop();
            count+=temp->importance;
            for(int i=0;i<temp->subordinates.size();i++)
                q.push(temp->subordinates[i]);
            
        }
        return count;
    }
};
