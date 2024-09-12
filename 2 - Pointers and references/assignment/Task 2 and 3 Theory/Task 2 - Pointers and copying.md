# Task 2

What will happen with the code under?

```cpp
char *line = nullptr;   // or char *line = 0;
strcpy(line, "This is a text");
```

In this case it will cause a Segmentation fault, this is because it dosent point to a valid memory address. If we would initilize to a char and create a allocated memory for the line it would run.

```cpp
int main() {
  char *line = new char[20];
  strcpy(line, "This is a text");
}
```
