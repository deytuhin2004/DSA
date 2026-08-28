class Solution {
public:

    void merge( vector<int>& nums, int mid, int l, int r){

        int n1 = mid-l+1;
        int n2 = r-mid;

        vector<int> arr1(n1);
        vector<int> arr2(n2);
        int k=l;
        

        for(int i=0; i<n1; i++){
            arr1[i] = nums[k];
            k++;
        }
        for(int i=0; i<n2; i++){
            arr2[i]  =  nums[k];
            k++;
        }

        int i=0,j=0;
        k=l;

        while( i<n1 && j<n2){
            if(arr1[i] <= arr2[j]){
                nums[k] = arr1[i];
                i++; 
            }else{
                nums[k] = arr2[j];
                j++; 
            }
            k++;
        }

        while( i<n1){
            nums[k] = arr1[i];
            i++;k++;
        }
        while( j<n2){
            nums[k] = arr2[j];
            j++;k++;
        }

    }

    void mergesort(vector<int>& nums, int l, int r){

        if(l >= r)return;
        int mid = l+(r-l)/2;

        mergesort(nums, l, mid);
        mergesort(nums, mid+1, r);

        merge(nums, mid, l,r);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};