#ifndef __VM_SWAP_H
#define __VM_SWAP_H
#ifdef PRJ3
#include "lib/kernel/bitmap.h"
#include "lib/kernel/list.h"
#include "devices/disk.h"
#include "threads/pte.h"
#include "threads/synch.h"

struct frame_elem
{
  struct list_elem elem;
  struct thread* pd_thread;
  uint32_t *pd;
  void* vaddr; /* corresponding page pointer */
};

void swap_table_bitmap_init (void);
void swap_table_bitmap_set (size_t idx, bool toset);
size_t swap_table_scan_and_flip (void);

void frame_table_init (void);
void frame_table_push_back (struct frame_elem* e);
struct frame_elem* frame_table_find_victim (void);
void frame_table_delete (uint32_t pd);
void frame_elem_delete (void* target_addr, uint32_t* target_pd);
size_t frame_table_size (void);

void swap_lock_acquire (void);
void swap_lock_release (void);

#endif
#endif
