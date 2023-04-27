struct uproc {
  int pid;       // Process ID
  int ppid;      // Parent Process ID 
  int state;     // Process state
  uint64 sz;     // Size of process memory (bytes)
  char name[16]; // Process name
  int priority;  // Current priority level
  int ticks;     // Current number of ticks used within the quantum
  int block_times; // Number of times this process has given up the processor before using a full quantum
  int quantum_times; // Number of times this process has used its full quantum at the current priority
};
