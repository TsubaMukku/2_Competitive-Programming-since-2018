

深さ優先探索（DFS: Depth First Search）
・状態の遷移が分岐するような処理を実装するのに有効である.
・DFS は現在の深さと見てる要素を対応付けるのがコツである

//ex 過去のコンテストでは，
//配列 A の要素 A[i] を端から「使う / 使わない」の処理(ABC119 - C)
//文字集合があって任意の文字列を後ろに結合していく処理(ABC029 - C)
    
// https://pyteyon.hatenablog.com/entry/2019/03/01/211133


実装
停止条件
分岐処理
の二つが大枠になります．

int dfs(int pos, ~~~) {
    // 停止条件
    // 深さに限らず，任意の停止条件を書く
    if (pos == N) return ~~~;

    // pos を進めながら（末端に進みながら）分岐処理
    // 末端まで到達した時それぞれの分岐から値が返される
    // for 文で書ける場合は for 文で実装
    int ret1 = dfs(pos + 1, 分岐 1);
    int ret2 = dfs(pos + 1, 分岐 2);
    int ret3 = dfs(pos + 1, 分岐 3);
    int ret4 = dfs(pos + 1, 分岐 4);
    ...

    // それぞれの分岐からの戻り値の処理を行う関数
    return func(ret1, ret2, ret3, ret4);
}


//　タイムスタンプの実装例
// 各頂点 vv に対し、最初に発見した段階と、vv の子孫たちも含めて探索を終えた段階とを表す

void dfs(const Graph &G, int v, int& ptr) {

    // 行きがけ順をインクリメントしながらメモ
    first_order[v] = ptr++;

    seen[v] = true; 
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, ptr);
    }

    // 帰りがけ順をインクリメントしながらメモ
    last_order[v] = ptr++;
}
