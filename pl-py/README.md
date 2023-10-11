# python3

## pythonic features

```python
# initialize a one-dimension array
n = 10
Array = [0] * 10

# initialize a MxN matrix (2-D array)
Matrix = [[0]*N for _ in range(M)]
# or,
Mat = [[0]*N]*M
```

## howto

### [sorting](https://docs.python.org/3/howto/sorting.html)

* Either ```sorted()``` returns a new sorted (ascending) list, or

```python
>>> sorted([5, 2, 3, 1, 4])
[1, 2, 3, 4, 5]
```

* ```list.sort()``` modifies the list in-place.

```python
>>> a = [5, 2, 3, 1, 4]
>>> a.sort()
>>> a
[1, 2, 3, 4, 5]
``` 

* Both ```list.sort()``` and ```sorted()``` accept a ```reverse``` parameter with a boolean value, ```True``` for descending order.
