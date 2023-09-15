class Solution {
public:

    int seg[4*100001];

    void build( int ind, int l, int r, vector<int> &a ){
        if ( l == r ){
            seg[ind] = a[l];
            return; 
        } int mid = (l+r)/2;
        build(2*ind+1,l,mid,a);
        build(2*ind+2,mid+1,r,a);
        seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }

    int query( int ind, int l, int r, int low, int high ){
        if ( high < l || low > r ) return INT_MIN;
        if ( high >= r && low <= l ) return seg[ind];
        int mid = (l+r)/2;
        int left = query(2*ind+1,l,mid,low,high);
        int right = query(2*ind+2,mid+1,r,low,high);
        return max(left,right);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        build(0, 0, nums.size()-1, nums);
        vector<int> res;
        for(int i=0;i<nums.size()-k+1;i++){
            int ans = query(0, 0, nums.size()-1, i, i+k-1);
            res.push_back(ans);
        }
        return res;
    }
};