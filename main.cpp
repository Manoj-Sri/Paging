#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

const int MAX_TIME = 100000;

int number_of_processes =0, latest_time_stamp = -1;


#include "includes/structs/structs_root.h"
PROCESS* all_processes;
process_q* process_queue;
frame_list* mem_frame_list;

#include "includes/root.h"









void start_time();


int main()
{

  int page_size = 0;
  int mem_size = 0;

  char* file_name = (char*)malloc(100 * sizeof(char));

  get_user_input(&mem_size,&page_size, file_name);

  all_processes = read_processes_from_file(file_name);

  process_queue = create_process_queue(number_of_processes);

  mem_frame_list = create_frame_list(mem_size/page_size,page_size);

  start_time();

  return 0;
}










void start_time()
{

  long time = 0;

  while(1)
  {

    enqueue_newly_arrived_process(time);

    terminate_completed_process(time);


    assign_available_memory_to_waiting_process(time);






    time++;

    if(time > MAX_TIME)
    {
      cout << "DEADLOCK: max  time reached" << endl;
      break;
    }

    if(process_queue->size == 0 && frame_list_is_empty(mem_frame_list))
      break;

  }

  print_turnaround_time();
}
