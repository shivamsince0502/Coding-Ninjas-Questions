#define ll long long

//function for extended culedian algo used to find modulare inverse
ll gcdExt(ll a, ll b, ll *x, ll *y) {
  // base case
  if(a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  // to stroe results of recursive calls
  ll x1, y1;
  ll gcd = gcdExt(b%a, a, &x1, &y1);

  // update x and y using results of recursive calls
  *x = y1 - (b/a) * x1;
  *y = x1;
  return gcd;
}

// function to mid the modulo inverse of b with modulo m
ll modInv(ll b, ll m) {
  ll x, y;
  gcdExt(b, m, &x, &y);

  // adding m to handel negative value of m
  return (x%m + m) % m;
} 

// function to computer a/b under modulo m;
ll modDiv(ll a, ll b, ll m) {
  a = a%m;
  ll inv = modInv(b, m);
  return (inv*a)%m;
}

int jumbledPens(int n, int red, int green, int blue) {
  /*
    Total number of distinct permutations of given pens = n! / (red! * blue! * green!)
  */
 const int mod = 1e9+7;
 ll numerator = 1, denominator = 1;

  // calculating n! in numerator
  for(int i = 2; i <= n; i++) {
    numerator = numerator * i % mod;
  }

  // now calculating red! * green! * blue! in denominator
  for(int i = 2; i <= green; i++) {
    denominator = denominator * i % mod;
  }

  for (int i = 2; i <= red; i++)
  {
    denominator = denominator * i % mod;
  }

  for (int i = 2; i <= blue; i++)
  {
    denominator = denominator * i % mod;
  }

  // dividing numrator by denominator under modulo 1e9+7;
  return modDiv(numerator, denominator, mod);

}
