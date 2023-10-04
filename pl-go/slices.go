package main

import (
  "fmt"
//  "slices"
)

func main() {
  // a slice
  primes := [6]int{2, 3, 5, 7, 11, 13}
  // [low: high) the index starting from 0
  // left included, right open and not included
  var s1 []int = primes[1:4] // [1, 4)
  fmt.Println(s1)

  // slices
  var s []string
  fmt.Println("uninitialized:", s, s==nil, len(s)==0)

  s = make([]string, 3)
  fmt.Println("emp:", s, "len:", len(s), "cap:", cap(s))

  s[0] = "a"
  s[1] = "b"
  s[2] = "c"
  fmt.Println("set:", s)
  fmt.Println("get:", s[2])
  fmt.Println("len:", len(s))

  s = append(s, "d")
  s = append(s, "e", "f")
  fmt.Println("apd:", s)

  twoD := make([][]int, 3)
  for i := 0; i < 3; i++ {
    innerLen := i + 1
    twoD[i] = make([]int, innerLen)
    for j := 0; j < innerLen; j++ {
      twoD[i][j] = i + j
    }
  }
  fmt.Println("2d: ", twoD)
}
