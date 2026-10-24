class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> elem_freq;
        vector<int> max_elems;
        int max_elem = INT_MIN;

        for (int i = 0; i < k; ++i) {
            if (nums[i] > max_elem) {
                max_elem = nums[i];
            }
            elem_freq[nums[i]]++;
        }
        max_elems.push_back(max_elem);
        int r = k, l = 0, n = nums.size();
        
        while (r < n) {
            // Remove the left most element
            elem_freq[nums[l]]--;
            elem_freq[nums[r]]++;
            if (elem_freq[nums[l]] == 0) {
                elem_freq.erase(nums[l]);
            }

            // Worst case we need to find the maximum elem
            if (nums[l] == max_elem) {
                max_elem = INT_MIN;
                for (const auto& [key, value] : elem_freq) {
                    if (key > max_elem) {
                        max_elem = key;
                    }
                }
            } else {
                if (nums[r] > max_elem) {
                    max_elem = nums[r];
                }
            }
            r++; l++;

            max_elems.push_back(max_elem);
        }
        return max_elems;
    }
};
