




void get_user_input(int *mem_size,int *page_size,char* file_name);

int multiple_of_hundred(int x);

int is_among_options(int x);

void clear_stdin(char* buffer);

int validate_input(const char* display,int (*func)(int));

void get_file_name(char* file_name);













void get_user_input(int *mem_size,int *page_size, char* file_name)
{

  while(1)
  {

    *mem_size = validate_input("Memory Size : ",multiple_of_hundred);

    int page_option = validate_input("Page Size(1: 100, 2: 200, 3: 400) : ",is_among_options);

    switch(page_option)
    {
      case 1: *page_size = 100; break;
      case 2: *page_size = 200; break;
      case 3: *page_size = 400; break;
    }

    if( (*mem_size) % (*page_size) == 0)
      break;

    cout << "Memory size must be multiple of page size" << endl <<
            *mem_size << "is not a multiple of " << *page_size << endl;
  }

  get_file_name(file_name);
}












int multiple_of_hundred(int x)
{
  return (x % 100) == 0 ? 1 : 0;
}









int is_among_options(int x)
{
  return (x>=1 && x<=3) ? 1 : 0;
}







void clear_stdin(char* buffer)
{
  if(buffer[strlen(buffer) - 1] != '\n')
  {
    int ch;
    while( ((ch = getchar()) != '\n' ) && (ch != EOF)) ;
  }
}








int validate_input(const char* display,int (*func)(int))
{
  char buffer[10];
  int valid = 0;
  int input;

  while(!valid)
  {
    cout << display ;

    fgets(buffer,10,stdin);

    if(sscanf(buffer,"%d",&input) <= 0)
    {
      clear_stdin(buffer);
      cout << "ERROR: u didnt enter number" << endl;
      continue;
    }

    if( (*func)(input))
    {
      valid = 1;
    }
    else
    {
      clear_stdin(buffer);
      cout << "ERROR: number is not a valid choics" << endl;
    }

  }

  return input;

}

















void get_file_name(char* file_name)
{

  char buffer[100];
  FILE* file_ptr;

  while(1)
  {
    cout  << "Input file : ";

    fgets(buffer,100,stdin);

    if(sscanf(buffer,"%s",file_name) <= 0)
    {
      clear_stdin(buffer);
      cout << " ERROR: u didnt enter a string";
      continue;
    }

    if(file_ptr = fopen(file_name,"r"))
      break;
    else
      perror("error: couldnt open file\n");

  }
}
