//
// Created by MLG Erwich on 15/01/2022.
//
#include <iostream>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Projectile.h"
using namespace std;

#ifndef SPACE_INVADERS_QUEUE_H
#define SPACE_INVADERS_QUEUE_H

// Define the default capacity of a queue
#define SIZE 10

// A class to store a queue
class Queue
{
  Projectile *arr[SIZE];      // array to store queue elements
  int capacity;   // maximum capacity of the queue
  int front;      // front points to the front element in the queue (if any)
  int rear;       // rear points to the last element in the queue
  int count;      // current size of the queue

 public:
  Queue(int size = SIZE);     // constructor
  ~Queue();                   // destructor

  Projectile dequeue();
  void enqueue(Projectile *x);
  Projectile& peek();
  int size();
  bool isEmpty();
  bool isFull();
  Projectile* getElement(int element);
  //void remove(Projectile &element, Queue& q);
};

#endif // SPACE_INVADERS_QUEUE_H
