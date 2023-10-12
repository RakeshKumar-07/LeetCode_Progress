/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int vis[10000];

    int findPivot(int l, int h, int n, MountainArray &mountainArr){
        if(l>h) return h;
        int mid = l + (h-l)/2;
        if(mid+1 < n) if(vis[mid+1] == -1) vis[mid+1] = mountainArr.get(mid+1);
        if(vis[mid] == -1) vis[mid] = mountainArr.get(mid);
        if(mid-1 >= 0) if(vis[mid-1] == -1) vis[mid-1] = mountainArr.get(mid-1);
        if(mid+1 < n && mid-1 >= 0  && vis[mid] > vis[mid+1] && vis[mid] > vis[mid-1]) return mid;
        if(mid+1 < n && vis[mid] < vis[mid+1]) return findPivot(mid+1, h, n, mountainArr);
        return findPivot(l, mid-1, n, mountainArr);
    }

    int bSL(int l, int h, int target, MountainArray &mountainArr){
        if(l>h) return -1;
        int mid = l + (h-l)/2;
        if(vis[mid] == -1) vis[mid] = mountainArr.get(mid);
        if(vis[mid] == target) return mid;
        if(vis[mid] < target) return bSL(mid+1, h, target, mountainArr);
        return bSL(l, mid-1, target, mountainArr);
    }

    int bSR(int l, int h, int target, MountainArray &mountainArr){
        if(l>h) return -1;
        int mid = l + (h-l)/2;
        if(vis[mid] == -1) vis[mid] = mountainArr.get(mid);
        if(vis[mid] == target) return mid;
        if(vis[mid] < target) return bSR(l, mid-1, target, mountainArr);
        return bSR(mid+1, h, target, mountainArr);
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        memset(vis, -1, sizeof(vis));

        int n = mountainArr.length();
        int pivot = findPivot(0, n-1, n, mountainArr);

        int L = bSL(0, pivot, target, mountainArr);
        if(L != -1) return L;
        
        int R = bSR(pivot+1, n-1, target, mountainArr);
        if(R != -1) return R;
        
        return -1;
    }
};