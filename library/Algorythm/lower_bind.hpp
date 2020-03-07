// 最も大きい外れ値を事前に入れる必要がある
// p 以上の中で最小のもの
template <typename T>
ll lb(T& v, ll p){
    auto start = v.begin()-1;
    auto end = v.end();
    auto md = start;
    while(end-start!=1){
        auto dif = (end - start)/2;
        md = start+dif;
        if(*md<p) start = md;
        else if(p<=*md) end = md;
    }
    return *end;
}
