class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {  
        vector<int> taskFreq(26, 0);
        priority_queue<pair<int, char>> maxPq; // {numberOfTasks, taskType}

        // Update task frequency vector
        for (int i = 0; i < tasks.size(); ++i)
        {
            char tsk = tasks[i];
            taskFreq[tsk - 'A']++;
        }


        // Create max heap; loop through all taskTypes to avoid pushing duplicates
        char tsk = 'A';
        for (int i = 0; i < 26; ++i)
        {
            if (taskFreq[tsk - 'A'] > 0)
            {
                maxPq.push({taskFreq[tsk - 'A'], tsk});
            }
            tsk++;
        }

        // cout << "Looping an printing all taskFreq values\n";
        // tsk = 'A';
        // for (int i = 0; i < 26; ++i)
        // {
        //     if (taskFreq[tsk - 'A'] > 0)
        //     {
        //         cout << "\tTask frequency of task: " << tsk << " is " << taskFreq[tsk - 'A'] << "\n";
        //     }
        //     tsk++;
        // }


        int cycles = 0;
        queue<tuple<char, int, int>> waitingTasks; // taskType, numberOfTasks, timeToWait
        while (!maxPq.empty() || !waitingTasks.empty())
        {
            cycles++;
            // Decrement all waiting counts
            cout << "===cycle " << cycles << "===\n";
            cout << "cycle " << cycles << " and the waiting queue has " << waitingTasks.size() << " elements\n";
            int waitingSize = waitingTasks.size();
            for (int i = 0; i < waitingSize; ++i)
            {
                tuple<char, int, int> t = waitingTasks.front();
                waitingTasks.pop();

                int& timeToWait = get<2>(t);
                timeToWait--;
                if (timeToWait == -1)
                {
                    char taskType = get<0>(t);
                    int numberOfTasks = get<1>(t);
                    cout << "cycle " << cycles << ": task " << taskType << " no longer has to wait!\n"; 
                    maxPq.push({numberOfTasks, taskType});
                } 
                else
                {
                    // Continue waiting
                    waitingTasks.push(t);
                }
            }


            if (!maxPq.empty())
            {
                pair<int, char> taskToRun = maxPq.top();
                maxPq.pop();

                cout << "cycle " << cycles << " and we popped off " << taskToRun.second << "\n";

                // Decrement the number of tasks left
                taskToRun.first--;

                // If this isn't the last task of this kind, push it and wait
                if (taskToRun.first > 0)
                {
                    char taskType = taskToRun.second;
                    int numberOfTasks = taskToRun.first;
                    int timeToWait = n;
                    waitingTasks.push({taskType, numberOfTasks, timeToWait});
                }
            }
        }
        return cycles;
    }
};
