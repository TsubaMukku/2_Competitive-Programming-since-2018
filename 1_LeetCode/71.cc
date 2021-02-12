

// 2021/02/12
class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream ss(path); // 文字列分割の準備をする
        string s; // /の手前までの文字列を収納するための変数を準備する
        stack<string> st; // 答えを得るための部分文字列を収納する
        
        
        // ssの中から/区切りで文字列を取得してsへ格納する
        while (getline(ss,s,'/')){
            
            if (s == "") continue; // //の場合
            else if (s == ".") continue;
            else if (s != "..") st.push(s);
            else{
                // s == ".."の場合である
                if (st.size()) st.pop();
            }
        }
        
        if (st.size() == 0) return "/";
        string ans = "";
        
        while (st.size()){
            string tmp = st.top();
            st.pop();
            
            ans = "/" + tmp + ans;
        }
        
        return ans;
    }
};

/*
ぜその解法が思い付かなかったのか
・特殊な操作（pop）が必要になるのは".."の場合のみという点に着目できなかった
・・・具体例からそのポイントを抽出できなかった


どういう思考が足りなかったのか
具体例を通した状況把握、場合分けの検討により
・//の中身を取ってきて、それぞれに対して場合分けを行う、という方針を立てられなかった
・・・・//の中身を取る方法（STL）を知らなかったため、その発想ができなくて当然だと思った



もし必要とされる思考法が足りていたとしたら解法を思い付けたのか
・yes

*/

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
