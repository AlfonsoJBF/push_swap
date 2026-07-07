*Este proyecto ha sido creado como parte del currículo de 42 por mtapiado, albustos.*

# push_swap

`push_swap` is a sorting project written in C.

The goal is to sort a stack of integers using only a limited set of stack operations, while producing the shortest possible sequence of valid instructions.

This project was developed by **mtapiado** and **albustos** as part of the 42 curriculum. It focuses on algorithmic complexity, stack manipulation, robust parsing, memory management, benchmarking and collaborative software design.

---

## Description

`push_swap` receives a list of integers as input and prints a sequence of operations that sorts them in ascending order.

At the beginning of the program:

- Stack `a` contains all the input numbers.
- Stack `b` is empty.
- The smallest number must end at the top of stack `a`.
- The program must print only valid Push_swap operations, one per line.

The challenge is not simply to sort numbers. The challenge is to sort them efficiently under a strict operation model. Instead of using a standard array-sorting function, the program must generate a valid sequence of stack instructions.

Allowed operations:

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of `b` to `a` |
| `pb` | Push the first element of `a` to `b` |
| `ra` | Rotate stack `a` upwards |
| `rb` | Rotate stack `b` upwards |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` at the same time |

The project implements several sorting strategies and allows the user to select which one to run.

---

## Instructions

### Compilation

Compile the mandatory program:

```bash
make
```

This creates:

```bash
./push_swap
```

Compile the bonus checker:

```bash
make bonus
```

This creates:

```bash
./checker
```

Clean object files:

```bash
make clean
```

Remove object files and binaries:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

### Usage

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

The program prints the operations required to sort the stack:

```txt
pb
ra
pb
pa
pa
```

Count the number of operations:

```bash
./push_swap 4 67 3 87 23 | wc -l
```

Validate the result with the checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

```txt
OK
```

---

### Strategy flags

The program supports the following strategy flags:

| Flag | Strategy |
|---|---|
| `--simple` | Forces `selection_sort` |
| `--medium` | Forces `chunk_sort` |
| `--complex` | Forces `k_sort` |
| `--adaptive` | Chooses the strategy based on the disorder index |
| `--bench` | Prints benchmark information to `stderr` |

If no strategy is specified, the program uses the adaptive strategy by default.

Examples:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

---

### Benchmark mode

Benchmark mode is enabled with:

```bash
--bench
```

Benchmark information is printed to `stderr`, while the list of operations remains in `stdout`.

Example:

```bash
ARG="$(shuf -i 0-9999 -n 100 | tr '\n' ' ')"
./push_swap --bench $ARG 2> bench.txt | ./checker $ARG
cat bench.txt
```

The benchmark output includes:

- Disorder index.
- Selected strategy.
- Complexity class.
- Total number of operations.
- Number of operations by type:
  - `sa`
  - `sb`
  - `ss`
  - `pa`
  - `pb`
  - `ra`
  - `rb`
  - `rr`
  - `rra`
  - `rrb`
  - `rrr`

This mode was used during development to compare strategies, tune performance and verify real operation counts.

---

### Bonus checker

The bonus part implements a custom `checker`.

Compile it with:

```bash
make bonus
```

Use it like this:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

If the operations sort stack `a` and leave stack `b` empty, the checker prints:

```txt
OK
```

If the operations are valid but do not sort the stack, it prints:

```txt
KO
```

If the input or an instruction is invalid, it prints:

```txt
Error
```

The checker reads instructions from standard input, executes them on the received stack and verifies the final state.

---

### Error handling

The parser rejects invalid input and prints:

```txt
Error
```

to `stderr`.

Invalid cases include:

- Non-integer arguments.
- Values outside the `int` range.
- Duplicate numbers.
- Empty arguments.
- Invalid flags.
- Invalid checker instructions.

Examples:

```bash
./push_swap 1 2 one 4
```

```txt
Error
```

```bash
./push_swap 3 2 3
```

```txt
Error
```

---

## Algorithms

The project implements four strategies:

- Simple strategy: `selection_sort`
- Medium strategy: `chunk_sort`
- Complex strategy: `k_sort`
- Adaptive strategy: disorder-based selection

Before sorting, the program assigns an index to each number according to its sorted position.

Example:

```txt
Values:   42  -3  100  7
Indexes:   2   0    3  1
```

This index normalization makes the algorithms independent from the original integer values. It simplifies comparisons, chunk ranges and maximum/minimum searches.

---

### Simple strategy: selection_sort

Used with:

```bash
--simple
```

This strategy repeatedly finds the minimum value in stack `a`, moves it to the top and pushes it to stack `b`.

Process:

1. Find the minimum node in stack `a`.
2. Move it to the top using the cheapest rotation direction.
3. Push it to stack `b`.
4. Repeat until stack `a` is empty.
5. Push everything back to stack `a`.

Complexity in the Push_swap operation model:

| Metric | Complexity |
|---|---|
| Operations | `O(n²)` |
| Extra space | `O(1)` besides the stacks |

Reason for choosing it:

`selection_sort` is simple, predictable and useful as a baseline strategy. It is not the best algorithm for large inputs, but it is easy to verify and helped validate the correctness of the stack operations before implementing more advanced strategies.

---

### Medium strategy: chunk_sort

Used with:

```bash
--medium
```

This strategy divides the input into chunks of indexes. Instead of extracting one value at a time, it processes ranges of values and moves them from stack `a` to stack `b`.

Process:

1. Define a chunk size according to the input size.
2. Push values belonging to the current chunk from `a` to `b`.
3. Rotate `b` when useful to improve its internal distribution.
4. Once all values are in `b`, move the maximum value to the top.
5. Push values back to `a` in descending order.

Complexity in the Push_swap operation model:

| Metric | Complexity |
|---|---|
| Operations | `O(n√n)` |
| Extra space | `O(1)` besides the stacks |

Reason for choosing it:

`chunk_sort` is a strong intermediate strategy. It improves over the simple algorithm by grouping values into ranges, reducing the cost of repeatedly searching for isolated minimums or maximums.

---

### Complex strategy: k_sort

Used with:

```bash
--complex
```

This strategy is designed for larger and more disordered inputs. It uses indexed values and a decision window to decide when to push and rotate elements.

Process:

1. Work with normalized indexes.
2. Push eligible values from stack `a` to stack `b`.
3. Rotate stack `b` selectively to create a useful distribution.
4. Rebuild stack `a` by repeatedly moving the maximum value in `b` to the top.
5. Push the maximum back to `a`.

Complexity in the Push_swap operation model:

| Metric | Complexity |
|---|---|
| Target strategy class | `O(n log n)` |
| Extra space | `O(1)` besides the stacks |

Reason for choosing it:

`k_sort` gives the best practical performance for large random inputs. It works especially well with index normalization and provides strong results for 500-number tests.

---

## Adaptive strategy

Used with:

```bash
--adaptive
```

The adaptive strategy computes a disorder index before sorting.

The disorder index measures how far the original stack is from being sorted. It is based on inverted pairs: a pair is inverted when a bigger number appears before a smaller number.

The result is a value between `0` and `1`:

| Disorder value | Meaning |
|---|---|
| `0` | Already sorted |
| Close to `0` | Almost sorted |
| Close to `1` | Highly disordered |
| `1` | Maximally disordered |

The adaptive strategy uses these thresholds:

| Disorder range | Selected algorithm |
|---|---|
| `< 0.2` | `selection_sort` |
| `0.2 <= disorder < 0.5` | `chunk_sort` |
| `>= 0.5` | `k_sort` |

Justification:

- Low disorder inputs do not need a heavy algorithm. `selection_sort` is simple and avoids unnecessary overhead.
- Medium disorder inputs benefit from range-based sorting. `chunk_sort` gives a better balance between simplicity and performance.
- High disorder inputs require the strongest strategy. `k_sort` gives the best average performance for large and random inputs.

This makes the program react to the shape of the input instead of relying only on input size.

---

## Performance

Average observed performance:

| Input size | Average operations |
|---|---|
| 100 numbers | Less than 600 operations |
| 500 numbers | Around 5000 operations |

Example test:

```bash
ARG="$(shuf -i 0-9999 -n 500 | tr '\n' ' ')"
./push_swap $ARG | wc -l
```

Validation:

```bash
ARG="$(shuf -i 0-9999 -n 500 | tr '\n' ' ')"
./push_swap $ARG | ./checker $ARG
```

Expected result:

```txt
OK
```

---

## Project structure

```txt
.
├── Makefile
├── README.md
├── include
│   ├── algorithms.h
│   ├── debug.h
│   ├── libraries.h
│   ├── operations.h
│   ├── parse.h
│   └── stack.h
├── libft
├── src
│   ├── algorithms
│   ├── debug
│   ├── main
│   ├── operations
│   ├── parseo
│   └── stack
└── src_bonus
    └── src_bonus
        ├── checker_bonus.c
        ├── checker_bonus.h
        ├── checker_exec_bonus.c
        ├── checker_read_bonus.c
        └── checker_utils_bonus.c
```

Main responsibilities:

| Directory | Purpose |
|---|---|
| `include/` | Header files and shared declarations |
| `libft/` | Custom C library |
| `src/main/` | Program entry point |
| `src/parseo/` | Parsing, flag handling and input validation |
| `src/stack/` | Stack and node management |
| `src/operations/` | Push_swap operations and primitive stack actions |
| `src/algorithms/` | Sorting strategies and algorithm utilities |
| `src/debug/` | Benchmark output |
| `src_bonus/` | Bonus checker |

---

## Contributions

This project was developed by **mtapiado** and **albustos**.

| Contributor | Main contribution |
|---|---|
| `mtapiado` | Parsing, flag handling, input validation, token processing and parser integration |
| `albustos` | Stack implementation, node management, primitive operations and Push_swap commands |
| Both | Algorithm design, adaptive strategy, benchmarking, testing, debugging and final integration |

Although responsibilities were divided, both contributors worked together on the algorithms and both understand the complete codebase.

---

## Resources

### Technical resources

The following resources were used during the project:

- 42 Push_swap subject.
- 42 Norm.
- C manual pages for `read`, `write`, `malloc`, `free` and `exit`.
- `libft`, developed as part of the 42 curriculum.
- `ft_printf`, developed as part of the 42 curriculum.
- `get_next_line`, used for the bonus checker input reading.
- Peer review and discussions with other 42 students.
- Practical testing with random inputs and checker validation.

### AI usage

AI tools were used as a learning assistant during the project.

They were used for:

- Discussing algorithmic strategies.
- Comparing possible approaches.
- Understanding complexity trade-offs.
- Reviewing edge cases.
- Structuring documentation.
- Improving the clarity of explanations.

All code was reviewed, tested and understood by the authors.

No AI-generated solution was copied blindly into the project. Every relevant idea was manually checked, adapted and validated.

---

## Final notes

`push_swap` is not only a sorting exercise.

It is a project about understanding how algorithms behave under constraints, how data structures affect performance and how to write reliable C code that can be tested, explained and maintained.