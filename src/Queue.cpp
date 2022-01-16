//
// Created by MLG Erwich on 15/01/2022.
//

#include "Queue.h"


// Constructor to initialize a queue
Queue::Queue(int size)
{
  for (int i = 0; i < SIZE; i++)
  {
    arr[i] = nullptr;
  }
  capacity = SIZE;
  front = 0;
  rear = -1;
  count = 0;
}

// Destructor to free memory allocated to the queue
Queue::~Queue() {
  for (int i = 0; i < SIZE; i++)
  {
    delete arr[i];
  }
}

// Utility function to dequeue the front element
Projectile Queue::dequeue()
{
  // check for queue underflow
  if (isEmpty())
  {
    cout << "Underflow\nProgram Terminated\n";
    exit(EXIT_FAILURE);
  }

  Projectile *x = arr[front];
  arr[front] = nullptr;
  cout << "Removing " << endl;

  front = (front + 1) % capacity;
  count--;

  return *x;
}

// Utility function to add an item to the queue
void Queue::enqueue(Projectile *item)
{
  // check for queue overflow
  if (isFull())
  {
    cout << "Overflow\nProgram Terminated\n";
    exit(EXIT_FAILURE);
  }

  cout << "Inserting " << item << " " << count << endl;

  rear = (rear + 1) % capacity;
  arr[rear] = item;
  count++;
}

// Utility function to return the front element of the queue
Projectile& Queue::peek()
{
  if (isEmpty())
  {
    cout << "Underflow\nProgram Terminated\n";
    exit(EXIT_FAILURE);
  }
  return *arr[front];
}

// Utility function to return the size of the queue
int Queue::size() {
  return count;
}

// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
  return (size() == 0);
}

// Utility function to check if the queue is full or not
bool Queue::isFull() {
  return (size() == capacity);
}

Projectile* Queue::getElement(int element)
{
  return arr[element];
}

/*
void Queue::remove(Projectile &element, Queue& q)
{
  int s = q.size();
  int cnt = 0;
  Projectile *temp[s];

  for (int i = 0; i < s; i++)
  {
    temp[i] = nullptr;
  }

  std::cout << "here" << std::endl;
    for (int i = 0; i < s; i++)
    {
      if (&q.peek() != &element)
      {
        temp[cnt] = &q.peek();
        q.dequeue();
        cnt++;
      }
    }

  std::cout << "here 2" << std::endl;

  if (q.isEmpty())
  {
    std::cout << "Element not found" << std::endl;
    for (int i = 0; i < cnt; i++)
    {
      q.enqueue(temp[i]);
    }
  }
  else
  {
    std::cout << "here 3" << std::endl;
    q.dequeue();
    for (int i = 0; i < cnt; i++)
    {
      q.enqueue(temp[i]);
    }
    std::cout << "here 4" << std::endl;

    for (int i = 0; i < cnt; i++)
    {
      Projectile p = q.peek();
      q.dequeue();
      q.enqueue(&p);
    }
  }
}*/