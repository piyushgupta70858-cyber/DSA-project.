/*
============================================================
Q1. Design and implement a stack using an array without
    using any built-in stack library.

Perform the following operations:
    1. PUSH(x)
    2. POP()
    3. PEEK()
    4. DISPLAY()

The program must handle both:
    - Stack Overflow
    - Stack Underflow

Additional Task:
1. Explain the time complexity and space complexity of
   each operation.
2. Discuss what happens when the stack size is fixed and
   the user attempts to insert more elements than its capacity.
============================================================
*/

#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// PUSH operation
void PUSH(int x)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow! Stack is full.\n");
        return;
    }

    top++;
    stack[top] = x;

    printf("\n%d pushed into the stack.\n", x);
}

// POP operation
void POP()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    printf("\n%d popped from the stack.\n", stack[top]);
    top--;
}

// PEEK operation
void PEEK()
{
    if (top == -1)
    {
        printf("\nStack Underflow! Stack is empty.\n");
        return;
    }

    printf("\nTop element is: %d\n", stack[top]);
}

// DISPLAY operation
void DISPLAY()
{
    if (top == -1)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements are:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n====================================\n");
        printf("       Q1: STACK USING ARRAY\n");
        printf("====================================\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                PUSH(value);
                break;

            case 2:
                POP();
                break;

            case 3:
                PEEK();
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("\nProgram ended successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

/*
============================================================
ADDITIONAL TASK - Q1

Time Complexity:

PUSH:
    O(1)

POP:
    O(1)

PEEK:
    O(1)

DISPLAY:
    O(n)

Space Complexity:

PUSH:
    O(1) extra space

POP:
    O(1) extra space

PEEK:
    O(1) extra space

DISPLAY:
    O(1) extra space

Overall space complexity of the stack:
    O(n)

Fixed Stack Size:

The stack has a fixed capacity of MAX = 5.

If the stack already contains 5 elements and the user tries
to insert another element, Stack Overflow occurs.

The new element cannot be inserted because the array has
reached its maximum capacity.
============================================================
*/
/*
============================================================
Q2. Implement a Circular Queue using an array.

The queue should support:
    1. ENQUEUE(x)
    2. DEQUEUE()
    3. FRONT()
    4. DISPLAY()

The implementation must correctly distinguish between:
    - A full queue
    - An empty queue

Additional Task:
Compare the circular queue with a simple linear queue
and explain:

1. Why a circular queue provides better utilization of memory.
2. Time complexity of ENQUEUE and DEQUEUE.
3. Space complexity of the queue.
4. What problem occurs in a linear queue when REAR reaches
   the last index even though unused positions exist at the
   beginning?
============================================================
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// ENQUEUE operation
void ENQUEUE(int x)
{
    // Check if queue is full
    if ((rear + 1) % MAX == front)
    {
        printf("\nQueue Overflow! Queue is full.\n");
        return;
    }

    // If queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;

    printf("\n%d inserted into the queue.\n", x);
}

// DEQUEUE operation
void DEQUEUE()
{
    // Check if queue is empty
    if (front == -1)
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    printf("\n%d removed from the queue.\n", queue[front]);

    // If only one element is present
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// FRONT operation
void FRONT()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nFront element is: %d\n", queue[front]);
}

// DISPLAY operation
void DISPLAY()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements are: ");

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n============================================\n");
        printf("      Q2: CIRCULAR QUEUE USING ARRAY\n");
        printf("============================================\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to ENQUEUE: ");
                scanf("%d", &value);
                ENQUEUE(value);
                break;

            case 2:
                DEQUEUE();
                break;

            case 3:
                FRONT();
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("\nProgram ended successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

/*
============================================================
ADDITIONAL TASK - Q2

1. Why does a circular queue provide better utilization
   of memory?

In a simple linear queue, after DEQUEUE operations, the
positions at the beginning of the array become empty.

When REAR reaches the last index, these empty positions
cannot normally be reused.

A circular queue solves this problem by connecting the last
position of the array back to the first position.

Therefore, positions freed by DEQUEUE can be reused.

This provides better utilization of memory.

------------------------------------------------------------

2. Time Complexity:

ENQUEUE:
    O(1)

DEQUEUE:
    O(1)

FRONT:
    O(1)

DISPLAY:
    O(n)

------------------------------------------------------------

3. Space Complexity:

The queue uses an array of size n.

Overall Space Complexity:
    O(n)

------------------------------------------------------------

4. Problem in a Linear Queue:

Suppose the queue has five positions:

[10] [20] [30] [40] [50]
 F                       R

After removing 10 and 20:

[  ] [  ] [30] [40] [50]
          F               R

The first two positions are empty, but REAR has already
reached the last index.

In a simple linear queue, new elements cannot be inserted
into those empty positions.

This causes wastage of available memory and is commonly
called the false overflow problem.

A circular queue solves this problem by allowing REAR to
wrap around to the beginning of the array.

The circular movement is performed using:

    (rear + 1) % MAX

------------------------------------------------------------

Full Queue Condition:

    (rear + 1) % MAX == front

Empty Queue Condition:

    front == -1
============================================================
*/

