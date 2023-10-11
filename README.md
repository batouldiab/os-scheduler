# OS Scheduler

OS Scheduler is a simple program that demonstrates process scheduling algorithms. It allows you to manage and schedule processes, providing insights into how different processes are executed over time.

## Features

- Add processes with CPU and I/O burst times.
- View available processes and their details.
- Delete processes based on their index.
- Simulate process execution and view the scheduling order.
- Find the process working at a specific time.
- Calculate waiting times for processes.

## Prerequisites

- C++ Compiler (Supporting C++11 standard)
- Standard Template Library (STL)

## How to Run

1. **Compile the Code:**
   ```bash
   g++ prog.cpp function.cpp Queue.cpp -o os-scheduler
   ```
2. **Run the Program:**
   ```bash
   ./os-scheduler
   ```

## Usage

### Queue Implementation

The program utilizes a queue data structure to manage processes. Here's how the queue is used:

- **Creating a Queue:**
  The program creates a queue for each process to manage CPU and I/O burst times.

- **Adding Elements to the Queue:**
  Processes' CPU and I/O burst times are enqueued into the respective process queues. The `EnQueue` function is used to add elements to the queue.

- **Removing Elements from the Queue:**
  Elements are dequeued from the front of the queue using the `DeQueue` function when the CPU or I/O burst is completed.

- **Checking Queue Status:**
  The program checks whether a queue is empty or full using the `isEmptyQueue` and `isFullQueue` functions to manage the queue operations effectively.

### Program Usage

Follow the on-screen instructions to interact with the program. You can add processes, delete them, simulate execution, find processes at specific times, and calculate waiting times.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please create an issue or make a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Note:** This project was created for educational purposes and may not cover all edge cases or be optimized for production environments
