/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "pack_animal.h"
#include "caravan.h"
#include <stdlib.h>

typedef struct _node
{
  PackAnimal pack_animal;
  struct _node* next;
}Node;

struct PackAnimalImplementation {
	AnimalType type;
	const char *name;
	int max_speed;
	int load;
	Caravan caravan;
};

struct CaravanImplementation
{
  Node* head;
};

Caravan new_caravan()
{
  Caravan caravan=(Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head=0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node* current_node=caravan->head;
  while (current_node!=0)
  {
    count++;
    current_node=current_node->next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  int length =get_length(caravan);
  for(int i =0; i <length; i++)
  {
    Node* head =caravan->head;
    caravan->head =head->next;
    free(head);
  }
  free(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if((animal == 0) || (animal->caravan == caravan))
  {
    return;
  }
  if(animal->caravan != 0)
  {
    remove_pack_animal(animal->caravan, animal);
  }

  animal->caravan = caravan;
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->pack_animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node* current_node = caravan->head;

  if(current_node == 0 || animal == 0)
  {
    return;
  }

  animal->caravan = 0;

  if(current_node->pack_animal == animal)
  {
    caravan->head = current_node->next;
    free(current_node);
    return;
  }

  while((current_node->next != 0) && (current_node->next->pack_animal != animal))
  {
    current_node = current_node->next;
  }

  if(current_node->next == 0)
  {
    return;
  }

  Node* node_next = current_node->next;
  current_node->next = node_next->next;
  free(node_next);
}

int get_caravan_load(Caravan caravan)
{
  int length = get_length(caravan);
  int load_count = 0;
  Node* current_node = caravan->head;

  for(int i = 0; i < length; i++)
  {
    load_count += current_node->pack_animal->load;
    current_node = current_node->next;
  }
  return load_count;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node* current_node = caravan->head;

  for(int i = 0; i < length; i++)
  {
    current_node->pack_animal->load = 0;
    current_node = current_node->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  int lowest_speed = 51;
  int length = get_length(caravan);

  Node* current_node = caravan->head;

  for(int i = 0; i < length; i++)
  {
    if(get_actual_speed(current_node->pack_animal) < lowest_speed)
    {
      lowest_speed = get_actual_speed(current_node->pack_animal);
    }
    current_node = current_node->next;
  }

  if(lowest_speed == 51)
  {
    lowest_speed = 0;
  }
  return lowest_speed;
}
