class Solution {
public:
    static bool cmp(vector<int>A, vector<int>B) {
        return A[1] < B[1]; 
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),cmp);
        priority_queue<int>pq;
        int time = 0;
        for(int i=0; i<courses.size(); i++) {
            if(courses[i][0] <= courses[i][1]) {
                if(courses[i][0] + time <= courses[i][1]) {
                    pq.push(courses[i][0]);
                    time += courses[i][0];
                }
                else if(pq.top() > courses[i][0]) {
                    // cout<<courses[i][0]<<endl;
                    time -= pq.top(); pq.pop();
                    pq.push(courses[i][0]);
                    time += courses[i][0];
                    // cout<<time<<
                }
            }
        }
        return pq.size();
    }
};