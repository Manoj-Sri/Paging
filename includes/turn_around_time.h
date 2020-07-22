
#include <iomanip> //for setprecision() function

void print_turnaround_time()
{

  float tot = 0;

  for(int i=0;i<number_of_processes;i++)
  {
    tot += all_processes[i].completion_time - all_processes[i].arrival_time;
  }

  float avg_tat = tot/number_of_processes;
  cout << "Average turn around time : " << fixed << setprecision(2) << avg_tat << endl;

}
