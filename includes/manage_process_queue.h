

process_q* create_process_queue(int number_of_processes);

void enqueue_process(process_q* q,PROCESS* p);

void dequeue_process(process_q* q);

void dequeue_process_at_index(process_q* q,int index);

PROCESS* next_process_in_queue(process_q* q);

void print_process_queue(process_q* q);


















process_q* create_process_queue(int number_of_processes)
{

  process_q* q = (process_q*)malloc(sizeof(process_q));

  q->elements = (PROCESS**)malloc(sizeof(PROCESS) * number_of_processes);
  q->size = 0;
  q->max_size = number_of_processes;
  q->front = 0;
  q->rear = -1;

  return q;
}













void enqueue_process(process_q* q,PROCESS* p)
{

  if(q->size == q->max_size)
  {
    cout << "ERROR : q is full " << endl;
    exit(2);
  }

  q->size++;
  q->rear = q->rear+1;
  if(q->rear == q->max_size)
    q->rear = 0;

  q->elements[q->rear] = p;
}










void dequeue_process(process_q* q)
{
  if(q->size == 0)
  {
    cout << "ERROR: q is empty " << endl;
    exit(2);
  }

  q->size--;
  q->front++;
  if(q->front == q->max_size)
    q->front = 0;

}














void dequeue_process_at_index(process_q* q,int index)
{

  int prev = 0;

  for(int i=0;i<q->size;i++)
  {
    if(i > index)
      q->elements[prev] = q->elements[i];

    prev = i;
  }
  q->size--;
  q->rear--;
}



PROCESS* next_process_in_queue(process_q* q)
{
  if(q->size == 0)
  {
    cout << "ERROR: q is empty " << endl;
    exit(2);
  }

  return q->elements[q->front];
}











void print_process_queue(process_q* q)
{
  PROCESS* p;

  cout << "\tInput Queue : [ ";
  for(int i=0;i < q->size;i++)
  {
    p = q->elements[q->front + i];
    cout << p->pid << " ";
  }
  cout << " ]" << endl;
}
