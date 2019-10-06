//iterative modular exponentiation
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus; //if the bit of exponent is set, multiply the base to the result
    base = (base * base) % modulus; //square the base
    exp >>= 1;  //divide the exponent by 2
  }
  return result;
}
