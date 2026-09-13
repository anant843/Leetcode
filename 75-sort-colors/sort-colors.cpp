class Solution {
public:
    void sortColors(vector<int>& nums) {

      int countzero=0;
      int countone=0;
      int counttwo=0;

      for(int x:nums){
        if(x==0)countzero++;
        else if(x==1)countone++;
        else counttwo++;
      }

      int i=0;

      while(countzero--){
        nums[i++]=0;
      }

      while(countone--){
        nums[i++]=1;
      }

      while(counttwo--){
        nums[i++]=2;
      }
    }
};