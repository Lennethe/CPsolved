
template <typename T>
T ext_gcd(T a, T b, T&x, T&y){
  if(b==0){
    x=1;y=0;return a;
  }
  T q=a/b;
  T g=ext_gcd(b,a-q*b,x,y);
  T z=x-q*y;
  x=y;y=z;
  return g;
}

// aは割る言、mがmod
template <typename T>
T invmod(T a, T m){
  T x,y;
  ext_gcd(a,m,x,y);
  x%=m;
  if(x<0)x+=m;
  return x;
}
