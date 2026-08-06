class Solution {
public:
    //commented approach
    string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (m == 0 || n < m) return "";
    
    // Hash map to store the frequency of characters in string 't'
    int hash[58] = {0}; 
    for (int i = 0; i < m; i++) {
        hash[t[i]-65]++;
    }
    
    int l = 0, r = 0; 
    int minLen = 1e9, sIndex = -1; // sIndex stores the starting index of the min window
    int cnt = 0; // Number of characters matched
    
    while (r < n) {
        // If the current character is required, increment the valid count
        if (hash[s[r]-65] > 0) {
            cnt++;
        }
        // Decrease the required frequency for the current character in the map
        hash[s[r]-65]--;
        
        // When all characters of 't' are matched, try to shrink the window
        while (cnt == m) {
            // Update the minimum window size and its starting index
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }
            
            // Shrink from the left
            hash[s[l]-65]++; // Add the character back to the map's required count
            
            // If we remove a character that was necessary to form 't', reduce our valid match count
            if (hash[s[l]-65] > 0) {
                cnt--;
            }
            
            l++; // Increment left pointer
        }
        
        r++; // Expand the window to the right
    }
    
    // Return the minimum substring, or an empty string if no valid window is found
    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
};