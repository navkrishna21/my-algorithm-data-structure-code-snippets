# Prime Factorization In log(n) After Sieve

We use Eratosthenes sieve for prime factorization, storing the primes in an array. But for that, we need to find the primes less than or equal to sqrt(n) which divide n. There are about n/log(n) primes less than or equal to n. So, the complexity is roughly sqrt(n)/log(sqrt(n))*log(n). But if n is asked to be factorized completely where n is within the Sieve range, then we can factorize n is log(n) complexity. And the trick is fairly small. Observe, that, we don't need to run a whole sqrt(n) loop for finding the prime divisors. Instead, we can even store them when n is in the range, say n<= 10^7. But the tricky part is not to store all the prime divisors of n. Let's see the following simulation. Take n = 60. We want to factorize n. We will store the smallest prime factors only. This does the trick. If n is composite, then it has such a prime factor, otherwise n is a prime and then the n itself is the smallest prime factor. It is obvious, for any even number n, sp(n)=2. Therefore, we only need to store these primes for odd n only. If we denote the smallest prime factor of n by sp(n), for odd 2 <= n <= 30, we get the following list.

sp(2n)=2, sp(3)=3, sp(5)=5, sp(7)=7, sp(9)=3, sp(11)=11, sp(13)=13, sp(15)=3, sp(17)=17, sp(19)=19, sp(21)=3, sp(23)=23, sp(25)=5, sp(27)=3, sp(29)=29.

Then the factorization is very simple. The optimization is needed only once, when the Sieve() function runs.


NOTE: You can't use this for n large enough in int range.
