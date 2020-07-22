

#ifndef process_structure
#define process_structure



typedef struct
{
  int pid;
  int arrival_time;
  int life_time;
  int mem_req;

  int active;
  int time_added_to_memory;
  int completion_time;
} PROCESS;


#endif
