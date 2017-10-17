# stl-utils
Single header library that has some STL utility functions.

## Available Functions

### Split
Behaves like explode in php or split in python and javascript.
`std::vector<std::basic_string<T>> split(const std::basic_string<T> &input, const char delimiter = ' ')`

Takes any basic_string, most notably `string` and `wstring` and a delimeter (it's a space by default).

#### Example:
`vector<string> words = RDI::split(sentence);`

### Concatenate Vectors
`std::vector<T> concat_vectors(std::vector<T> a, std::vector<T> b)`

Takes two vectors concatinates them and returns the result.

#### Example:
```C++
vector<int> x{1, 2, 3};
vector<int> y{4, 5};
vector<int> xy = RDI::concat_vectors(x, y); // {1, 2, 3, 4, 5}
```
