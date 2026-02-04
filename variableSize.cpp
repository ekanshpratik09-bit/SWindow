

int longestKSubstr(string s, int k) {
    int i = 0, j = 0;
    int n = s.length();
    int maxLen = -1; // Return -1 if no such substring exists
    unordered_map<char, int> m;

    while (j < n) {
        // 1. Calculation: Add current character to map
        m[s[j]]++;

        // 2. If unique characters are less than k, just move j
        if (m.size() < k) {
            j++;
        }
        // 3. If unique characters are exactly k, update maxLen
        else if (m.size() == k) {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        // 4. If unique characters exceed k, shrink the window from left
        else if (m.size() > k) {
            while (m.size() > k) {
                m[s[i]]--;
                if (m[s[i]] == 0) {
                    m.erase(s[i]); // Remove entry to decrease m.size()
                }
                i++;
            }
            j++;
        }
    }
    return maxLen;
}




// "Pick Toys" is a classic interview question (often called Fruit Into Baskets). 
//  This is identical to the Longest Substring with K Unique Characters problem.

int pickToys(string toys, int k) {
    int i = 0, j = 0;
    int maxToys = 0;
    unordered_map<char, int> basket; // Stores {toy_type: count}

    while (j < toys.length()) {
        // Add current toy to basket
        basket[toys[j]]++;

        // If types are within limit, update maxToys
        if (basket.size() <= k) {
            maxToys = max(maxToys, j - i + 1);
            j++;
        }
        // If types exceed k, shrink window from left
        else if (basket.size() > k) {
            while (basket.size() > k) {
                basket[toys[i]]--;
                if (basket[toys[i]] == 0) {
                    basket.erase(toys[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxToys;
}

