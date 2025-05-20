// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ares_comm:msg/Data.idl
// generated code does not contain a copyright notice
#include "ares_comm/msg/detail/data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ares_comm__msg__Data__init(ares_comm__msg__Data * msg)
{
  if (!msg) {
    return false;
  }
  // data_id
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    ares_comm__msg__Data__fini(msg);
    return false;
  }
  return true;
}

void
ares_comm__msg__Data__fini(ares_comm__msg__Data * msg)
{
  if (!msg) {
    return;
  }
  // data_id
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
ares_comm__msg__Data__are_equal(const ares_comm__msg__Data * lhs, const ares_comm__msg__Data * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data_id
  if (lhs->data_id != rhs->data_id) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
ares_comm__msg__Data__copy(
  const ares_comm__msg__Data * input,
  ares_comm__msg__Data * output)
{
  if (!input || !output) {
    return false;
  }
  // data_id
  output->data_id = input->data_id;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

ares_comm__msg__Data *
ares_comm__msg__Data__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__msg__Data * msg = (ares_comm__msg__Data *)allocator.allocate(sizeof(ares_comm__msg__Data), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ares_comm__msg__Data));
  bool success = ares_comm__msg__Data__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ares_comm__msg__Data__destroy(ares_comm__msg__Data * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ares_comm__msg__Data__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ares_comm__msg__Data__Sequence__init(ares_comm__msg__Data__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__msg__Data * data = NULL;

  if (size) {
    data = (ares_comm__msg__Data *)allocator.zero_allocate(size, sizeof(ares_comm__msg__Data), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ares_comm__msg__Data__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ares_comm__msg__Data__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ares_comm__msg__Data__Sequence__fini(ares_comm__msg__Data__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ares_comm__msg__Data__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ares_comm__msg__Data__Sequence *
ares_comm__msg__Data__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ares_comm__msg__Data__Sequence * array = (ares_comm__msg__Data__Sequence *)allocator.allocate(sizeof(ares_comm__msg__Data__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ares_comm__msg__Data__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ares_comm__msg__Data__Sequence__destroy(ares_comm__msg__Data__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ares_comm__msg__Data__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ares_comm__msg__Data__Sequence__are_equal(const ares_comm__msg__Data__Sequence * lhs, const ares_comm__msg__Data__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ares_comm__msg__Data__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ares_comm__msg__Data__Sequence__copy(
  const ares_comm__msg__Data__Sequence * input,
  ares_comm__msg__Data__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ares_comm__msg__Data);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ares_comm__msg__Data * data =
      (ares_comm__msg__Data *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ares_comm__msg__Data__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ares_comm__msg__Data__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ares_comm__msg__Data__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
