class Solution {

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskFreq;
        int time = 0;
        priority_queue<int> maxHeap;
        for (auto task: tasks){
            if (taskFreq.find(task)!= taskFreq.end()){
                taskFreq[task]++;
            }
            else{
                taskFreq.insert({task, 1 });
            }
        }
        for (auto task: taskFreq){
            maxHeap.push(task.second);
        }
        queue<pair<int, int>> taskQueue; //frequency and time
        //  n = 2
        //queue: 
        //t : 4
        while (!maxHeap.empty() || !taskQueue.empty()){
            if (!taskQueue.empty()){
                auto nextTask = taskQueue.front();
                if (time == nextTask.second){
                    taskQueue.pop();
                    maxHeap.push(nextTask.first);
                }
                else if (maxHeap.empty()){
                    taskQueue.pop();
                    maxHeap.push(nextTask.first);
                    cout << time << endl;
                    time = nextTask.second;
                }
            }
            if (!maxHeap.empty()){
                auto curTask = maxHeap.top();
                maxHeap.pop();
                if (curTask > 1){
                    taskQueue.push({curTask-1, time+ n + 1});
                }
                time++;
            }

        }
        return time;
    }
};
