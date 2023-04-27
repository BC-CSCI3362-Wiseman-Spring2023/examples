struct sysinfo {
  int num_harts;    // number of hardware threads
  int num_procs;    // number of processes
  uint64 total_mem; // total amount of memory in system (bytes)
  uint64 avail_mem; // total amount of available memory in system (bytes)
  uint64 proc_mem;  // total amount of available memory in system (bytes)
};
