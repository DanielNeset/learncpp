# Task 3

```cpp
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}
```

## Things that can go wrong

A user can input a text that is longer then the maximum 4 characters set in the text variable.

```cpp
char text[5];
cin >> text;
```

It will endup in a endless loop if the text dont have the character e in it, and might end with a crash.

```cpp
while (*pointer != search_for) {}
```

If we find the caracter e, the \*pointer will be set to e.

```cpp
*pointer = search_for; // The pointer will be equal to e
pointer++; // Move it to the next character of the text
```
