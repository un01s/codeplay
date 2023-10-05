# Go-lang


## hello

```
# just run the code
#
$ go run hello.go
hello

# build the code to generate an executable
#
$ go build hello.go
$ ./hello
hello

$ go run echo.go test 123 third
test 123 third
$ go run echo2.go test 123 third
test 123 third

# Go supports Unicode natively
# with http service integrated in standard package
# changes from single-computer with single-core to 
# networked computer with multiple cores
#
$ go run hello2.go
Check your localhost, http://127.0.0.1:12345/
2023/10/04 19:12:17 Hello, Go -- time: 2023-10-04 19:12:17.967192 -0600 MDT m=+12.943456126
```

## slices in Go-lang

An array has a fixed size. A slice is dynamically-sized, flexible view into the elements of an array. 


