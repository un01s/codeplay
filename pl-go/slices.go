package main

import "fmt"

func main() {
  // a slice
  primes := [6]int{2, 3, 5, 7, 11, 13}
  // [low: high) the index starting from 0
  // left included, right open and not included
  var s []int = primes[1:4] // [1, 4)
  fmt.Println(s)
}
