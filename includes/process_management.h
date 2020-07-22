
char* get_latest_time_stamp(int time);







void enqueue_newly_arrived_process(int time)
{

  PROCESS* p;

  for(int i=0;i<number_of_processes;i++)
  {
    p = &all_processes[i];

    if(p->arrival_time == time)
    {

      cout << get_latest_time_stamp(time) << "process " << p->pid
            << "   arrives" << endl;

      enqueue_process(process_queue,p);

       print_process_queue(process_queue);

      print_mem_frame_list(mem_frame_list);

    }
  }
}













void terminate_completed_process(int time)
{

  int time_spent_in_memory;
  PROCESS* p;

  for(int i=0;i<number_of_processes;i++)
  {
    p = &all_processes[i];

    time_spent_in_memory = time - p->time_added_to_memory;

    if(p->active && (time_spent_in_memory >= p->life_time))
    {
      cout << get_latest_time_stamp(time) << "process " << p->pid
          <<  " completes" << endl;

      p->active = 0;
      p->completion_time = time;

      free_memory_for_process(mem_frame_list,p);
      print_mem_frame_list(mem_frame_list);
    }
  }
}



















void assign_available_memory_to_waiting_process(int time)
{

  int index,processes_waiting;
  PROCESS* p;

  processes_waiting  = process_queue->size;

  for(int i=0;i < processes_waiting; i++)
  {
    index = process_queue->front + i;
    p = process_queue->elements[index];

    if(process_can_fit_in_mem(mem_frame_list,p))
    {
      cout << get_latest_time_stamp(time) << "MM moeves process  "
          << p->pid << " to memory " << endl;

      fit_process_in_memory(mem_frame_list,p);

      p->active = 1;
      p->time_added_to_memory = time;

      dequeue_process_at_index(process_queue,i);
      print_process_queue(process_queue);
      print_mem_frame_list(mem_frame_list);
    }
  }


}











char* get_latest_time_stamp(int time)
{

  char* display;

  display = (char*)malloc(sizeof(char) * 20);

  if(latest_time_stamp == time)
    sprintf(display,"\t");
  else
    sprintf(display, "t = %d: \n\t", time);


  latest_time_stamp = time;
  return display;
}
