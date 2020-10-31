#Euler Partitions
inspired by [This Daily Programmer challenge](https://old.reddit.com/r/dailyprogrammer/comments/jfcuz5/20201021_challenge_386_intermediate_partition/) and [This Mathologer video](https://www.youtube.com/watch?v=iJ8pnCO0nTY)

An implentation of Euler's pentagonal formula in C, using a struct to cache
results for the recursive calls. Should support up to p(7000)-ish using 128-bit
unsigned int's. It generates the partition points and stuff using the same
method in this Mathologer video and then uses the generated array to form the
summation for each p(n) with recursive calls. I tried threading some of it with
OMP but it had no effect on execution time, and TBH it's pretty quick already.