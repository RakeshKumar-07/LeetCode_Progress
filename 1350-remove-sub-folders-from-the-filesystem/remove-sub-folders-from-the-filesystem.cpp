class Solution {
public:
    vector<string> split( string &a ){
        int n = a.size(); string currS = ""; vector<string> res;
        for ( int i = 0; i<n; i++ ){
            if ( a[i] != '/' ) currS += a[i];
            else {
                res.push_back(currS);
                currS = "";
            }
        } res.push_back(currS); 
        return res;
    }
    bool isSubFolder( string &a, string &b ){
        vector<string> aSplit = split(a), bSplit = split(b);
        int n = aSplit.size(), m = bSplit.size(), i = 0, j = 0;
        while ( i < n && j < m && aSplit[i] == bSplit[j] ) i++, j++;
        return j == m;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size(); sort(folder.begin(), folder.end());
        vector<string> res; string currFolder = "##";
        for ( int i = 0; i<n; i++ ){
            if ( !isSubFolder(folder[i], currFolder) ){
                res.push_back(folder[i]);
                currFolder = folder[i];
            }
        } return res;
    }
};