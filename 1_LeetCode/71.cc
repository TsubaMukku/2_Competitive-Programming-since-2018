

// 2021/02/11
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> v;
        
        istringstream ss(path); // istringstreamを用いて入力を受け取る
        string token, res;
        
        // 標準入力から取得した文字列の分割を行う
        while (getline(ss,token,'/')){
            
            if (token == "" || token == ".") continue;
            else if (token != "..") v.push(token);
            else if (v.size())v.pop();
        }
        
        if (v.size() == 0) return "/";
        
        while(v.size()){
            string tmp = v.top();
            v.pop();
            res =  "/" + tmp + res;
        }
        return res;
    }
};

//https://qiita.com/tarokun/items/526c6d65d5b3024d6caa
