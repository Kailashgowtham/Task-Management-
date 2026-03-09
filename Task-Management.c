#include <stdio.h>
#include <string.h>

struct Task
{
    int no;
    char work[100];
    int status;
} task[100];
int count = 0;

void Addtask()
{
    printf("Add Task\n");
    scanf(" %[^\n]", task[count].work);
    task[count].no = count + 1;
    task[count].status = 0;
    count++;
    printf("Task added\n");
}

void Complete_task()
{
    int no;
    scanf("%d", &no);

    if (no > 0 && no <= count)
    {
        task[no - 1].status = 1;
        printf("Task completed\n");
    }
}

void Delete_task()
{
    int no;
    scanf("%d", &no);
    if (no > 0 && no <= count)
    {
        for (int i = no - 1; i < count - 1; i++)
        {
            task[i] = task[i + 1];
        }
        count--;
    }
}

void Display_task()
{
    if (count == 0)
    {
        printf("No Task is available\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d. %s %s\n", task[i].no, task[i].work, task[i].status ? "-> Done" : "-> Pending");
    }
}

int main()
{

    while (1)
    {
        printf("TO DO LIST\n");
        int choose;
        printf("1.Add Task\n2.Complete task\n3.Display task\n4.Delete task\n5.Exit\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            Addtask();
            break;
        case 2:
            Complete_task();
            break;
        case 3:
            Display_task();
            break;
        case 4:
            Delete_task();
            break;
        case 5:
            return 0;
        default:
            printf("Enter valid option\n");
        }
    }
}