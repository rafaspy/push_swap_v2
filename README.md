*This project has been created as part of the 42 curriculum by csekakul and rafsanch.*

# Description

The program takes a list of integers as arguments and outputs a sequence of operations that sorts the numbers in ascending order using two stacks (A and B) and a limited set of operations.

## Contributions

The work on this project was divided as follows:

- `rafsanch`: implemented the parsing logic, the `k_sort` algorithm, and error output handling. He also contributed to the benchmark mode and helped with the stack movement operations.
- `csekakul`: implemented the stack movement operations, `sort_small`, the benchmark mode, the medium and complex sorting algorithms, and the strategy flags.


At this stage, the program supports:

- **Parsing and Validation**
  - Accepts integers from command line arguments
  - Handles multiple numbers per argument
  - Validates input: only integers, no duplicates
  - Converts strings to integers and stores them in **stack A**

- **Stack Operations**
  - Swap operations: `sa`, `sb`, `ss`
  - Push operations: `pa`, `pb`
  - Rotate operations: `ra`, `rb`, `rr`
  - Reverse rotate operations: `rra`, `rrb`, `rrr`

## 1. Simple Algorithm — O(n²)

Implemented in: `simple_sort`

### Approach:
- Repeatedly push the smallest element from stack A to B
- Sort the remaining small subset (≤5 elements)
- Push elements back to A

### Characteristics:
- Deterministic and easy to implement
- Efficient for small inputs
- Not suitable for large datasets

---

## 2. Medium Algorithm — O(n√n)

Implemented in: `chunk_sort`

### Approach:
- Divide the indexed values into **chunks**
- Push elements from A to B based on chunk ranges
- Use rotations (`rb`) to position smaller elements deeper in B
- Reconstruct A by pushing back the largest elements first

### Key Idea:
- Reduces unnecessary movements by grouping values

### Tuning:
- Chunk size is proportional to input size (e.g., `n / 5`)
- Proper tuning significantly improves performance

### Performance:
- Designed to achieve **<700 operations for 100 numbers** (excellent target)

---

## 3. Complex Algorithm — O(n log n)

Implemented in: `radix_sort`

### Approach:
- Uses **binary radix sort**
- First normalizes values using indexing
- Sorts numbers bit by bit using `pb` and `ra`
- Rebuilds stack A after each bit pass

### Characteristics:
- Very stable and predictable
- Guarantees good performance for large inputs
- Not optimal for small or partially sorted datasets

---

## 4. Adaptive Algorithm — Hybrid Strategy

Implemented in: `adaptive_sort`

### Disorder Metric

Before sorting, the program computes a **disorder value (0 → 1)**:

- `0`: already sorted
- `1`: completely reversed
- Based on pairwise inversions

---

### Strategy Selection

| Disorder Range | Strategy Used | Complexity |
|---------------|--------------|-----------|
| `< 0.2`       | K sort     | ~O(n) |
| `< 0.5`       | Chunk sort | O(n√n) |
| `≥ 0.5`       | Radix sort | O(n log n) |

### Rationale:
- **Low disorder:** minimal fixes required → avoid heavy algorithms
- **Medium disorder:** chunking balances efficiency and control
- **High disorder:** radix guarantees consistent performance

---

## Small Stack Optimization (Critical)

Before applying any strategy, the program always handles small inputs:

- **2–3 elements:** optimal hardcoded logic (`sort_small`)
- **4–5 elements:** push smallest values to B, sort remaining, then restore

### Example:

| Input | Output |
|------|--------|
| `[3, 2, 1]` | `sa` `rra` |

This guarantees **minimal operations** and avoids unnecessary use of complex algorithms.

---

## Strategy Selection

The program supports runtime selection:

```bash
./push_swap [strategy] numbers...
```

---

## Algorithm Selection and Justification

### Small Stack Sorting (2–5 numbers)

1. **2–3 numbers:**
   - Simple comparison logic using `sa`, `ra`, `rra` to sort 2 or 3 numbers

2. **4–5 numbers:**
   - Find the smallest (or two smallest) numbers in stack A
   - Rotate stack A to bring the smallest to the top
   - Push smallest number(s) to stack B (`pb`)
   - Sort the remaining 3 numbers in stack A
   - Push numbers back from stack B to stack A (`pa`)
   - Rotations are chosen to minimize the number of moves

**Justification:**
- This approach is **deterministic and optimal for very small stacks**, ensuring minimal operations
- It is **scalable**, as the same push/pop strategy can be extended for larger sorting algorithms later (radix sort, etc.)
- Keeps code **modular and reusable**, separating operations from parsing and sorting logic

**Examples:**

| Input Stack | Output Operations |
|------------|-----------------|
| `[2, 1, 3]` | `sa` |
| `[3, 2, 1]` | `sa` `rra` |
| `[2, 3, 1]` | `rra` |
| `[1, 3, 2]` | `sa` `ra` |

- These sequences ensure the stack is sorted in ascending order with minimal moves.

---

### 3. Use of Two Stacks (A and B)
- Even though sorting ≤3 numbers does not require stack B, the project architecture uses two stacks in preparation for **sorting larger inputs**.
- All operations (push, swap, rotate, reverse rotate) are implemented for both stacks to allow scalability.

### Design Choices
- Array-based stacks for simplicity and performance
- Indexing system to normalize values for radix and chunk algorithms
- Modular structure:
	- Parsing
	- Operations
	- Strategies
- Adaptive approach to handle different input patterns efficiently

---

# Instructions
Compile the program using Makefile:

```bash
make
```
Compile the program manually:

```bash
cc -Wall -Wextra -Werror *.c -o push_swap
```
Run
```bash
./push_swap 3 2 1
```
Run with specific strategy
```bash
./push_swap --medium 5 2 8 1 3
```

# Resources
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push Swap Explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Inspiration](https://github.com/anyaschukin/Push_Swap)
- [Overview](https://github.com/AdrianWR/push_swap)
- [Jump/branch table](https://en.wikipedia.org/wiki/Branch_table)
- [Structures CS50 video](https://www.youtube.com/watch?v=E4lb2gkyXr8)
- [Structs CS50 video](https://www.youtube.com/watch?v=yMvRqKmbRm4)
- [Defining custom types CS50 video](https://www.youtube.com/watch?v=96M4q0OnMfY)
- [Struct Wikipedia](https://en.wikipedia.org/wiki/Struct_(C_programming_language)#:~:text=In%20the%20C%20programming%20language,single%20identifier%2C%20often%20a%20pointer.)

## AI Assistance

During the development of this project, AI tools  were used for:

- **Clarifying concepts**: understanding stack operations, parsing, and sorting logic.
- **Planning**: designing the step-by-step approach for small stack sorting.
- **Debugging guidance**: identifying compilation errors, type mismatches, and improving function structure.
- **Writing README and documentation**: creating clear explanations of algorithms and program structure.

### Important Notes

- No AI-generated code was used to bypass learning objectives.
- All **final implementations were written and tested manually**.
- AI assistance was strictly used as a **learning and planning aid**, similar to consulting with peers or mentors.
