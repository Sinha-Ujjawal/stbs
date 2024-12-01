# Algorithms in C
This is a [stb](https://github.com/nothings/stb) style library implementing basic algorthms in C.
This is only for recreational purpose and not for any real world use. If you still want to use this in your project, feel free to do so at your own risk.

# Following algorithms are currently implemented

| Function        | Signature                                 | Description                                                            |
| --------------- | ----------------------------------------- | ---------------------------------------------------------------------- |
| bisect\_left    | (target, low, high, fn\_key)              | bisect\_left impl. similar to (bisect library)[https://docs.python.org/3/library/bisect.html] in python |
| bisect\_right   | (target, low, high, fn\_key)              | bisect\_right impl. similar to (bisect library)[https://docs.python.org/3/library/bisect.html] in python |
| heapify         | (arr, count, fn\_compare, root)           | heapify impl.     |
| build\_heap     | (arr, count, fn\_compare)                 | build\_heap impl. |
| build\_heap     | (arr, count, fn\_compare)                 | build\_heap impl. |
| heapsort        | (arr, count, fn\_compare)                 | heapsort impl.    |

# Example program
[example.c](./example.c)
