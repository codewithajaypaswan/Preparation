class NumArray {
public:
    vector<int>tree;
    int n;
    void build(int node, int st, int en, vector<int>&nums) {
        if(st == en) {
            tree[node] = nums[st];
            return;
        }
        int mid = (st + en)/2;
        build(2*node+1, st, mid, nums);
        build(2*node+2, mid+1, en, nums);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(0, 0, n-1, nums);
    }
    void updateUntil(int index, int val, int l, int r, int node) {
        if(index < l || index > r) return;
        if(l == r) {
            if(index == l) tree[node] = val;
            return;
        }
        
        int mid = (l + r)/2;
        updateUntil(index, val, l, mid, 2*node+1);
        updateUntil(index, val, mid+1, r, 2*node+2);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    void update(int index, int val) {
        if(n == 0) return;
        updateUntil(index, val, 0, n-1, 0);
        // for(int i=0; i<tree.size(); i++) cout<<tree[i]<<" ";
        // cout<<endl;
    }
    int sumRangeUntil(int left, int right, int l, int r, int node) {
        if(left <= l && r <= right) return tree[node];
        if(r < left || l > right) return 0;
        int mid = (l + r)/2;
        return sumRangeUntil(left, right, l, mid, 2*node+1) + sumRangeUntil(left, right, mid+1, r, 2*node+2);
    }
    int sumRange(int left, int right) {
        if(n == 0) return 0;
        return sumRangeUntil(left, right, 0, n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */