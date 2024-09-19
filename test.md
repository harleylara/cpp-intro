# Quick Evaluation

Note: this is not an exhaustive evaluation of the language and all its features, it is simply intended to illustrate some interesting points to motivate the study of C++.

## Variables

```cpp
// is this valid C++ code?
int c(3);
int d();
int e{2};
int f{};
```

```cpp
// how many bits are we allocating here?
unsigned short int test;
```

## Loops

```cpp
// is this valid C++ code ?
for (const auto number: numbers) {
  std::cout << number << std::endl;
}
```

## Functions

```cpp
// this if for free, What is going on here?
template <class T, int N>
T times(T a)
{
    return a*N;
}
```

## Name Visibility

```cpp

// any syntax error here?
int a = 4;

int main() {
  a:: = 8;
  ::a = 3;
  return 0;
}

```

```cpp
// what is the expected output?
int x;

int main ()
{
  int y;
  std::cout << x << '\n';
  std::cout << y << '\n';
  return 0;
}

```

## Other Types

```
// What is the difference between my_int and var?
typedef int my_int = 8;
int var = 9;
```

