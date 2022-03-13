#include "llist.hh"
#include <assert.h>

LNode* find(LNode* head, data_t value)
{
  while (head) {
    if (value == head->data_) {
      return head;
    }
    head = head->next_;
  }
  return nullptr;
}

LNode* find_alt(LNode* head, data_t value)
{
  if (!head) {
    return nullptr;
  }

  if (value == head->data_) {
    return head;
  }
  else {
    return find(head->next_, value);
  }
}


void delete_list(LNode* head)
{
  while (head) {
    auto save = head->next_;
    delete head;
    head = save;
  }
}

void delete_list_alt(LNode* head)
{
  if (!head) {
    return;
  }
  delete_list_alt(head->next_);
  delete head;
}

void append(LNode* n1, LNode* n2)
{
  assert(n2);
  assert(n1);
  n2->next_= n1->next_;
  //Not complete
}