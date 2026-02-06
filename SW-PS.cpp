

// Sum == K ;  ==> min_Window
//             ==> max_Window

// Sum >= K ;  ==> min_Window
//             ==> max_Window


// only +ve numbers are present then SW bec val becrease when window shrink ;
// when -ve also present then PS applied ;



int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // prefixSum -> first index
    mp[0] = -1;    🔥🔥🔥

    int prefixSum = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        if (mp.count(prefixSum - k)) {
            ans = max(ans, i - mp[prefixSum - k]);
        }

        // store earliest index only  🔥🔥🔥
        if (!mp.count(prefixSum)) {
            mp[prefixSum] = i;
        }
    }
    return ans;
}




int minSubArrayLenEqual(int target, vector<int>& nums) {
    unordered_map<int, int> mp; // prefixSum -> index
    mp[0] = -1;

    int prefixSum = 0;
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        if (mp.count(prefixSum - target)) {
            ans = min(ans, i - mp[prefixSum - target]);
        }

        // store latest index for minimum length    🔥🔥🔥
        mp[prefixSum] = i;
    }

    return (ans == INT_MAX) ? 0 : ans;
}




int minSubArrayLenEqual(int target, vector<int>& nums) {
    int i = 0, sum = 0;
    int ans = INT_MAX;

    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];

        while (sum >= target) {
            if (sum == target) {
                ans = min(ans, j - i + 1);
            }
            sum -= nums[i];
            i++;
        }
    }

    return (ans == INT_MAX) ? 0 : ans;
}




int maxSubArrayLen(vector<int>& nums, int target) {
    int i = 0, sum = 0, ans = 0;

    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];

        while (sum > target) {
            sum -= nums[i];
            i++;
        }

        if (sum == target) {
            ans = max(ans, j - i + 1);
        }
    }

    return ans;
}




🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄


int maxSubArrayLenAtLeast(int target, vector<int>& nums) {
    int prefixSum = 0;
    int minPrefix = 0;
    int minIndex = -1;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];

        if (prefixSum - minPrefix >= target) {
            ans = max(ans, i - minIndex);
        }

        // update minimum prefix sum
        if (prefixSum < minPrefix) {
            minPrefix = prefixSum;
            minIndex = i;
        }
    }

    return ans;
}



int minSubArrayLen(int k, vector<int>& nums) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + nums[i];

    deque<int> dq;
    int ans = INT_MAX;

    for (int i = 0; i <= n; i++) {

        // Check if we found a valid window
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }

        // Maintain increasing prefix sum order
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return ans == INT_MAX ? 0 : ans;
}


int minSubArrayLen(int k, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= k) {
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return ans == INT_MAX ? 0 : ans;
}



int maxSubArrayLen(int k, vector<int>& nums) {
    int n = nums.size();
    int sum = 0, left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        if (sum >= k) {
            ans = max(ans, right - left + 1);
        }
    }

    return ans;   // 0 if no subarray satisfies condition
}



🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄🌺🌕🏀🍁🌸🌞🔵🔴💎🍄



int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // prefixSum -> frequency
    mp[0] = 1;      🔥🔥🔥

    int prefixSum = 0;
    int count = 0;

    for (int x : nums) {
        prefixSum += x;

        if (mp.count(prefixSum - k)) {      
            count += mp[prefixSum - k];     //  how many times (prefixSum - k) appeared before
        }

        mp[prefixSum]++;
    }

    return count;
}
