//要素の組み合わせを求めるのに用いる
//a[要素] = 要素の数, b[要素] = 要素の数
// => aとbの和の組み合わせの数

const double pi = std::acos(-1.0);

using type = std::complex<long double>;

std::vector<type> fft(std::vector<type> v, bool inv = false) {
  ll const n = v.size();
  double theta = 2 * pi / n * (inv ? -1 : 1);
  for (ll m = n; m >= 2; m >>= 1) {
    ll mh = m >> 1;
    type theta_i(0, theta);
    for (ll i = 0; i < mh; i++) {
      type w = std::exp((type)i * theta_i);
      for (ll j = i; j < n; j += m) {
        type x = v[j] - v[j + mh];
        v[j] = v[j] + v[j + mh];
        v[j + mh] = w * x;
      }
    }
    theta *= 2;
  }
  ll i = 0;
  for (ll j = 1; j < n - 1; j++) {
    for (ll k = n >> 1; k > (i ^= k); k >>= 1)
      ;
    if (j < i) std::swap(v[i], v[j]);
  }
  if (inv) {
    for (auto &x : v) x /= n;
  }
  return v;
}

std::vector<long long> convolution(std::vector<type> x, std::vector<type> y) {
  ll sz = 1;
  ll t = x.size() + y.size() - 1;
  while (sz < t) {
    sz <<= 1;
  }
  x.resize(sz);
  y.resize(sz);
  x = fft(std::move(x));
  y = fft(std::move(y));
  for (ll i = 0; i < sz; i++) {
    x[i] *= y[i];
  }
  x = fft(std::move(x), true);
  vector<long long> res(sz);
  for(ll i=0; i<sz; i++) res[i] = (long long)(x[i].real() + 0.5);
  return res;
}

