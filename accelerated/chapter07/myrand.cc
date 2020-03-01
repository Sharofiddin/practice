#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <limits.h>

using namespace std;

#define MY_RAND_MAX 32767

long long nrand(long long n) {
  if (n <= 0){
    cerr << n;
    throw domain_error("Argument to nrand is out of range");
}
  long long r;

  if (n <= MY_RAND_MAX) {						       
    const int bucket_size = MY_RAND_MAX / n;

    do {
      int bucket = rand() / bucket_size;
      r = bucket;
    } while (r >= n);
  } else {
    const long long bucket_size = ceil(n / MY_RAND_MAX);

    do {
      const long long bucket = nrand(MY_RAND_MAX);
      const long long remainder = nrand(bucket_size);
      r = (bucket - (bucket > 0 ? 1 : 0)) * bucket_size + remainder;
    } while (r >= n);
  }

  return r;
}

int main() {
  long long limit;
  srand(0);
  while (true){
    limit = nrand(LONG_LONG_MAX);
   if ( limit < 0 ){
        cout << limit << endl;
       break;
   }
  }
  return 0;
}