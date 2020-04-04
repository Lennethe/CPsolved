#include <iostream>
#include <bits/stdc++.h>

//要素の組み合わせを求めるのに用いる
//a[要素] = 要素の数, b[要素] = 要素の数
// => aとbの和の組み合わせの数

const double pi = std::acos(-1.0);
using type = std::complex<long double>;

std::vector<type> fft(std::vector<type> v, bool inv = false) {
  long long const n = v.size();
  double theta = 2 * pi / n * (inv ? -1 : 1);
  for (long long m = n; m >= 2; m >>= 1) {
    long long mh = m >> 1;
    type theta_i(0, theta);
    for (long long i = 0; i < mh; i++) {
      type w = std::exp((type)i * theta_i);
      for (long long j = i; j < n; j += m) {
        type x = v[j] - v[j + mh];
        v[j] = v[j] + v[j + mh];
        v[j + mh] = w * x;
      }
    }
    theta *= 2;
  }
  long long i = 0;
  for (long long j = 1; j < n - 1; j++) {
    for (long long k = n >> 1; k > (i ^= k); k >>= 1)
      ;
    if (j < i) std::swap(v[i], v[j]);
  }
  if (inv) {
    for (auto &x : v) x /= n;
  }
  return v;
}

std::vector<long long> convolution(std::vector<type> x, std::vector<type> y) {
  long long sz = 1;
  long long t = x.size() + y.size() - 1;
  while (sz < t) {
    sz <<= 1;
  }
  x.resize(sz);
  y.resize(sz);
  x = fft(std::move(x));
  y = fft(std::move(y));
  for (long long i = 0; i < sz; i++) {
    x[i] *= y[i];
  }
  x = fft(std::move(x), true);
  std::vector<long long> res(sz);
  for(long long i=0; i<sz; i++) res[i] = (long long)(x[i].real() + 0.5);
  return res;
}

