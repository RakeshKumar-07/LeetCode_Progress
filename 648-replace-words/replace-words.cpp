class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> v;
        string s = "";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i] == ' '){
                v.push_back(s);
                s = "";
            }
            else s += sentence[i];
        }
        v.push_back(s);
        s = "";
        vector<bool> vis(v.size(), false);
        sort(dictionary.begin(), dictionary.end());
        for(int i=0;i<dictionary.size();i++){
            for(int j=0;j<v.size();j++){
                if(!vis[j] && v[j].size() >= dictionary[i].size() && dictionary[i] == v[j].substr(0, dictionary[i].size())){
                    v[j] = dictionary[i];
                    // cout<<i<<","<<j<<": "<<dictionary[i]<<" => "<<v[j]<<endl;
                    vis[j] = true;
                }
            }
        }
        for(int i=0;i<v.size()-1;i++) s += (v[i] + " ");
        s += v[v.size()-1];
        return s;
    }
};