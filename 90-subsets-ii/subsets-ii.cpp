class Solution {
public:
    void solve(vector<int> &nums, int index, vector<int> &ans, set<vector<int>>&st) {
        if (index == nums.size()) {
            st.insert(ans);
            return;
        }

        solve(nums, index + 1, ans, st);

        ans.push_back(nums[index]);
        solve(nums, index + 1, ans, st);
        ans.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>ans;
        solve(nums,0,ans,st);
        vector<vector<int>>result(st.begin(),st.end());
        return result;
    }
};