// class Solution {
// public:
//     void sortColors(vector<int>& nums) {

//       int countzero=0;
//       int countone=0;
//       int counttwo=0;

//       for(int x:nums){
//         if(x==0)countzero++;
//         else if(x==1)countone++;
//         else counttwo++;
//       }

//       int i=0;

//       while(countzero--){
//         nums[i++]=0;
//       }

//       while(countone--){
//         nums[i++]=1;
//       }

//       while(counttwo--){
//         nums[i++]=2;
//       }
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }

            else if(nums[mid]==1){
                mid++;
            }

            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};