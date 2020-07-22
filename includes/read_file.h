//read file and create a list of all processes in the filePtr

PROCESS* read_processes_from_file(char* file_name);

int get_number_of_processes_from_file(FILE* file_ptr);







PROCESS* read_processes_from_file(char* file_name)
{

  int no_of_segments , each_segment_mem , total_mem;
  FILE* file_ptr = fopen(file_name,"r");

  number_of_processes = get_number_of_processes_from_file(file_ptr);

  PROCESS *process_list = (PROCESS*)malloc(number_of_processes * sizeof(PROCESS));

  if(!file_ptr)
  {
    cout << "ERROR : cant open file " << file_name;
    exit(1);
  }

  int i=0;
  while( !feof(file_ptr) && i < number_of_processes)
  {

    fscanf(file_ptr, "%d %d %d %d",
                      &(process_list[i].pid),
                      &(process_list[i].arrival_time),
                      &(process_list[i].life_time),
                      &no_of_segments
          );

    total_mem = 0;
    for(int j=0;j< no_of_segments;j++)
    {
      fscanf(file_ptr,"%d",&each_segment_mem);
      total_mem += each_segment_mem;
    }

    process_list[i].mem_req = total_mem;
    process_list[i].active = 0;
    process_list[i].time_added_to_memory = -1;
    process_list[i].completion_time = -1;

    i++;
  }

  fclose(file_ptr);
  return process_list;




}














int get_number_of_processes_from_file(FILE* file_ptr)
{
  int x=0;
  fscanf(file_ptr,"%d",&x);
  return x;
}
