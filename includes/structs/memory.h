typedef struct
{
  int assigned;
  char location[40];
  int process_assigned;
  int page_number;
} FRAME;


typedef struct
{
  FRAME* frames;
  int number_of_frames;
  int page_size;
} frame_list;
