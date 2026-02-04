

long maximumSumSubarray(int k, vector<int>& arr) {
    int i = 0; // Left pointer
    int j = 0; // Right pointer
    long sum = 0;
    long max_sum = 0;
    int n = arr.size();

    while (j < n) {
        // 1. Calculations: Add the current element to the window sum
        sum += arr[j];

        // 2. Expand window until size is k
        if (j - i + 1 < k) {
            j++;
        }
        // 3. Window size is exactly k
        else if (j - i + 1 == k) {
            // Update the maximum result
            max_sum = max(max_sum, sum);

            // 4. Slide the window: 
            // Subtract the element at the 'i' (front) before moving i
            sum -= arr[i];
            
            i++;
            j++;
        }
    }
    return max_sum;
}


// *****************************************************************************************************

int countAnagrams(string txt, string pat) {
    unordered_map<char, int> m;
    for (char c : pat) m[c]++;

    int k = pat.length();
    int count = m.size(); // Number of distinct characters to match
    int i = 0, j = 0;
    int ans = 0;

    while (j < txt.length()) {
        // Calculation: If char is in map, decrease its frequency
        if (m.find(txt[j]) != m.end()) {
            m[txt[j]]--;
            if (m[txt[j]] == 0) count--;
        }

        // Window size less than k, just expand
        if (j - i + 1 < k) {
            j++;
        }
        // Window size exactly k
        else if (j - i + 1 == k) {
            // If count is 0, all characters matched their frequencies
            if (count == 0) ans++;

            // Slide the window: Reverse the calculation for txt[i]
            if (m.find(txt[i]) != m.end()) {
                if (m[txt[i]] == 0) count++;
                m[txt[i]]++;
            }
            i++;
            j++;
        }
    }
    return ans;
}



❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌


vector<long long> printFirstNegativeInteger(long long arr[], int n, int k) {
    deque<long long> dq;
    vector<long long> ans;
    int i = 0, j = 0;

    while (j < n) {
        // 1. Process the current element: if negative, add to queue
        if (arr[j] < 0) {
            dq.push_back(arr[j]);
        }

        // 2. Expand the window until it reaches size k
        if (j - i + 1 < k) {
            j++;
        }
        // 3. When window size is exactly k
        else if (j - i + 1 == k) {
            // If queue is empty, no negative integer in this window
            if (dq.empty()) {
                ans.push_back(0);
            } else {
                // Front of queue is the first negative integer
                ans.push_back(dq.front());
                
                // If the element leaving the window is the one in the queue, pop it
                if (arr[i] == dq.front()) {
                    dq.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}



🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆🔆



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Using deque for better performance than list
        int i = 0, j = 0;
        int n = nums.size();

        // Edge case: if k is larger than array size, return the max of the whole array
        if (k > n) {
            if (n > 0) ans.push_back(*max_element(nums.begin(), nums.end()));
            return ans;
        }

        while (j < n) {
            // Maintain decreasing order in deque
            while (!dq.empty() && dq.back() < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            // Expand window until it reaches size k
            if ((j - i + 1) < k) {
                j++;
            } 
            // When window size is exactly k
            else {
                ans.push_back(dq.front());

                // Slide the window: if the element leaving is the current max, remove it
                if (dq.front() == nums[i]) {
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
