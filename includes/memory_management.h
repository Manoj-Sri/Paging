


frame_list* create_frame_list(int number_of_frames,int page_size);

int process_can_fit_in_mem(frame_list* list,PROCESS* p);

void fit_process_in_memory(frame_list* list,PROCESS* p);

void print_mem_frame_list(frame_list* list);

int frame_list_is_empty(frame_list* list);

void free_memory_for_process(frame_list* list,PROCESS* p);












frame_list* create_frame_list(int number_of_frames,int page_size)
{
  frame_list* f = (frame_list*)malloc(sizeof(frame_list));

  f->frames = (FRAME*)malloc(sizeof(FRAME) * number_of_frames);
  f->page_size = page_size;
  f->number_of_frames = number_of_frames;

  for(int i=0;i < number_of_frames; i++)
    f->frames[i].assigned = 0;

  return f;

}










int process_can_fit_in_mem(frame_list* list,PROCESS* p)
{
  int num_of_free_frames = 0;

  for(int i=0;i<list->number_of_frames;i++)
    if(!list->frames[i].assigned)
      num_of_free_frames++;

  return (num_of_free_frames * list->page_size) >= p->mem_req ;
}









void fit_process_in_memory(frame_list* list,PROCESS* p)
{

  int current_page = 1,remaining_mem_req = p->mem_req;

  for(int i=0;i < list->number_of_frames;i++)
  {
    if(!list->frames[i].assigned)
    {
      list->frames[i].assigned = 1;
      list->frames[i].process_assigned = p->pid;
      list->frames[i].page_number = current_page;

      current_page++;

      remaining_mem_req -= list->page_size;
    }

    if(remaining_mem_req <= 0)
      break;
  }
}

























void print_mem_frame_list(frame_list* list)
{

  int in_free_frame = 0,start_of_free_frame;

  cout << "\tMemory Map : " << endl;

  int i=0;
  for(i=0;i< list->number_of_frames;i++)
  {
    if((list->frames[i].assigned == 0) && !in_free_frame )
    {
      in_free_frame = 1;
      start_of_free_frame = i;
    }

    else if(in_free_frame && list->frames[i].assigned)
    {
      in_free_frame = 0;
      cout << "\t\t"<<start_of_free_frame*(list->page_size) << "-" << (i*list->page_size-1)
          <<  " :  Free frame(s)" << endl;
    }

    if(list->frames[i].assigned)
    {
      cout << "\t\t" << (i*list->page_size) << "-" << ( (i+1) * list->page_size -1)
          <<  " :  Process " << list->frames[i].process_assigned << ", page " << list->frames[i].page_number
          << endl;
    }

  }

  if(in_free_frame)
  {
    cout << "\t\t" <<start_of_free_frame * list->page_size << "-"
        << i*list->page_size-1 << " :  Free Frame(s)" << endl;
  }
}














int frame_list_is_empty(frame_list* list)
{
  for(int i=0;i<list->number_of_frames;i++)
    if(list->frames[i].assigned)
      return 0;

  return 1;
}



















void free_memory_for_process(frame_list* list,PROCESS* p)
{
  int pid = p->pid;
  FRAME* f;
  for(int i=0;i<list->number_of_frames;i++)
  {
    f = &list->frames[i];

    if(f->process_assigned == pid)
    {
      f->process_assigned = 0;
      f->page_number = 0;
      f->assigned = 0;
    }
  }
}
